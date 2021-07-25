#include "printf.h"

/**
 * p_char - Prints an only char.
 * @list: list that contains value
 * to print
*/
void get_func(char format, data_t datas)
{
	int i = 0;

    while (!i)
    {
        if (datas[i].type[0] == format)
            return datas[i].data_proto;
        i++;
    }
    return (NULL);
}

/**
 * e_newline - Prints \n.
 * @list: list that contains value
 * to print
*/
void e_newline(va_list list)
{
	printf("\n");
}

/**
 * e_tab - Prints \t.
 * @list: list that contains value
 * to print
*/
void e_tab(va_list list)
{
	printf("\t");
}

/**
 * e_back - Prints \b.
 * @list: list that contains value
 * to print
*/
void e_back(va_list list)
{
	printf("\b");
}

/**
 * e_newlinetab - Prints \f.
 * @list: list that contains value
 * to print
*/
void e_newlinetab(va_list list)
{
	printf("\f");
}

/**
 * e_vert - Prints \v.
 * @list: list that contains value
 * to print
*/
void e_vert(va_list list)
{
	printf("\v");
}

/**
 * e_return - Prints \r.
 * @list: list that contains value
 * to print
*/
void e_return(va_list list)
{
	printf("\r");
}

/**
 * p_char - Prints an only char.
 * @list: list that contains value
 * to print
*/
void p_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * p_string - Prints strings.
 * @list: list that contains value
 * to print
*/
void p_string(va_list list)
{
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * main - emulate the function of printf
 * @format: Amount of arguments received
 * Return: 0
*/

int main(const char * const format, ...)
{
    data_t datas[] = {
		{"c", p_char},
		{"s", p_string},
		{NULL, NULL}
	};
    data_t especials[] = {
		{"n", e_newline},
		{"t", e_tab},
		{"b", e_back},
		{"f", e_newlinetab},
        {"v", e_vert},
        {"r", e_return},
		{NULL, NULL}
	};

    int i = 0;
    char special_char;
    void (*token);
    char *printbuffer;
	va_list list;

	va_start(list, format);

    while (!format && !format[i])
    {
        special_char = format[i];

        if (special_char != '%' && special_char != '\\')
            printbuffer += format[i];

        else if (special_char == '%')
        {
            token = get_func(format[i + 1], datas);
            if (!token){
                printf("%s", printbuffer); //imprime buffer
                printbuffer = ""; //borramos buffer
                token(list);
                i++;
            }
        }
        else if (special_char == '\\')
        {
            token = get_func(format[i + 1], especials);
            if (!token){
                token(list);
            }
            else
                printbuffer += format[i + 1]; //add format[i+1] to buffer
            i++;
        }
        i++;
    }
    if (buffer != "")
        printf("%s", printbuffer); //imprime buffer
    va_end(list);
    return (0);
}