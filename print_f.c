#include "printf.h"

/**
 * print_f - emulate the function of printf
 * @format: Amount of arguments received
 * Return: 0
*/

void print_f(const char * const format, ...)
{
	va_list list;
	int i = 0, j = 0;
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
			printbuffer = _printmod(list, format[i + 1], printbuffer);
			j = 0;
			i++;
		}
		else if (special_char == 92)
		{
			printbuffer = _printspecials(format[i + 1], printbuffer, &i, &j);
		}
		i++;
	}
	if (printbuffer[0] != '\0')
		pbuffer(printbuffer); /*imprime buffer*/
	va_end(list);
	free(printbuffer);
}
/**
 * _printspecials - picks a function to print a format input
 * @format: character to compare
 * *@printbuffer: pointer to a buffer
 * *@i: loop counter for char
 * *@j: loop counte for printbuffer position
 * Return: Pointer to printbuffer
 */

char *_printspecials(char format, char *printbuffer, int *i, int *j)
{
	char *speciallist = "ntbfvr";
	int k = 0;

	while (speciallist[k] != '\0')
	{
		if (speciallist[k] == format)
		{
			printbuffer[*j] = 92 + format; /*imprime buffer*/
			(*j)++;
			break;
		}
		k++;
	}
	if (k >= 6)
	{
		printbuffer[*j] = format; /*add format[i+1] to buffer*/
		(*j)++;
	}
	(*i)++;
	return (printbuffer);
}
