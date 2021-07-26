#include "printf.h"

/**
 * pbuffer - Function #1: Prints and delete chars in buffer.
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
 * p_int - Prints integers.
 * @list: list that contains value
 * to print
*/

void p_int(va_list list)
{
	unsigned int i = va_arg(list, int);
	int size =i;
	int pot = 1, j, mod = pot;
	char *str;

	for (j = 0;  size > 0; j++)
        size /= 10;
	size = j;

	for(j = 1; j < size; j++)
		pot *= 10;
	str = malloc(size* sizeof(char));
	for(j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		str[size - 1 - j] = mod + '0';
		i /= 10;
	}
	str[0] = i + '0';
	write(1, str, size);
	/*printf("%s", str);*/
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
 * _printmod - picks a function to print a format input
 * 
 * @list:  argument list
 * @format: character to compare
 * *@printbuffer: pointer to a buffer
 * Return: Pointer to printbuffer
 */

char *_printmod(va_list list, char format, char * printbuffer)
{
 	int k = 0;
	data_t datas[] = {
		{"c", p_char},
		{"s", p_string},
        	{"d", p_int},
        	{"i", p_int},
		{NULL, NULL}
	};


        while (k < 4)
        {
		if (datas[k].type[0] == format)
                {
                    pbuffer(printbuffer); /*imprime buffer*/
                    datas[k].data_proto(list);
                    break;
                }
                k++;
        }
	return (printbuffer);
}
