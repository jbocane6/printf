#include "printf.h"
#include <stdio.h>
#include <string.h>

/**
 * pbuffer - Prints and delete chars in buffer.
 * @printbuffer: string to print
*/
void pbuffer(char *printbuffer)
{
    unsigned int i, j;

    for (i = 0; printbuffer[i] != '\0'; i++)
        ;
    /*printf("%s", printbuffer);*/
    write(1, printbuffer, i);

    for (j = 0; j < i; j++)
        printbuffer[j] = '\0';
}
/**
 * p_char - Prints an only char.
 * @list: list that contains value
 * to print
*/
/*void get_func(char format, data_t datos[])
{
	int i = 0;

    while (!i)
    {
        if (datos[i].type[0] == format)
            return (datos[i].data_proto);
        i++;
    }
    return (NULL);
}*/

/**
 * e_newline - Prints \n.
 * @list: list that contains value
 * to print
*/
void e_newline()
{
	printf("\n");
}

/**
 * e_tab - Prints \t.
 * @list: list that contains value
 * to print
*/
void e_tab()
{
	printf("\t");
}

/**
 * e_back - Prints \b.
 * @list: list that contains value
 * to print
*/
void e_back()
{
	printf("\b");
}

/**
 * e_newlinetab - Prints \f.
 * @list: list that contains value
 * to print
*/
void e_newlinetab()
{
	printf("\f");
}

/**
 * e_vert - Prints \v.
 * @list: list that contains value
 * to print
*/
void e_vert()
{
	printf("\v");
}

/**
 * e_return - Prints \r.
 * @list: list that contains value
 * to print
*/
void e_return()
{
	printf("\r");
}

/**
 * p_int - Prints integers.
 * @list: list that contains value
 * to print
*/
void p_int(va_list list)
{
	printf("%i", va_arg(list, int));
}

/**
 * p_char - Prints an only char.
 * @list: list that contains value
 * to print
*/
void p_char(va_list list)
{
    char i = va_arg(list, int);
    write(1, &i, 1);
	/*printf("%c", va_arg(list, int));*/
}

/**
 * p_string - Prints strings.
 * @list: list that contains value
 * to print
*/
void p_string(va_list list)
{
	char *str = va_arg(list, char *);
    write(1, str, strlen(str));
	/*printf("%s", str);*/
}

/**
 * print_f - emulate the function of printf
 * @format: Amount of arguments received
 * Return: 0
*/

void print_f(const char * const format, ...)
{
    data_t datas[] = {
		{"c", p_char},
		{"s", p_string},
        {"d", p_int},
        {"i", p_int},
		{NULL, NULL}
	};
    char_t especials[] = {
		{"n", e_newline},
		{"t", e_tab},
		{"b", e_back},
		{"f", e_newlinetab},
        {"v", e_vert},
        {"r", e_return},
		{NULL, NULL}
	};
    
    va_list list;
    unsigned int i = 0, j = 0, k;
    char special_char;
    char *printbuffer;

	va_start(list, format);
    printbuffer = malloc(sizeof(char) * strlen(format));
    while (format != NULL && format[i] != '\0')
    {
        special_char = format[i];
        /*printf("%d = %c\n", i, special_char);*/
        /*printf("%d\n", i);*/

        if (special_char != '%' && special_char != 92)
        {
            printbuffer[j] = format[i];
            j++;
        }
        else if (special_char == '%')
        {
            k = 0;
            while (k < 4)
            {
                if (datas[k].type[0] == format[i + 1])
                {                
                    pbuffer(printbuffer); /*imprime buffer*/
                    j = 0;
                    datas[k].data_proto(list);
                    break;
                }
                k++;
            }
            i++;
        }
        else if (special_char == 92)
        {
            printf("%c", special_char);
            k = 0;
            while (k < 6)
            {
                if (especials[k].type[0] == format[i + 1])
                {
                    pbuffer(printbuffer); /*imprime buffer*/
                    j = 0;
                    especials[k].data_proto();
                    break;
                }
                k++;
            }
            if (k >= 6)
            {
                printbuffer[j] = format[i + 1]; /*add format[i+1] to buffer*/
                j++;
            }
            i++;
        }
        i++;
    }
    if (printbuffer[0] != '\0')
        pbuffer(printbuffer); /*imprime buffer*/
    va_end(list);
    free(printbuffer);
}