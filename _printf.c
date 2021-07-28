#include "holberton.h"

/**
 * _printf - emulate the function of printf
 * @format: Amount of arguments received
 * Return: 0
*/

int _printf(const char * const format, ...)
{
	va_list list;
	int i = 0, j = 0, counter = 0, size;
	char special_char, *printbuffer;

	va_start(list, format);
	if (format == NULL || list == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	size = strlen(format);
	printbuffer = malloc(sizeof(char) * size);
	if (printbuffer == NULL)
		return (-1);
	while (i < size)
	{
		special_char = format[i];

		if (special_char != '%' && special_char != 92)
		{
			counter++;
			printbuffer[j] = format[i];
			j++;
		}
		else if (special_char == '%')
		{
			printbuffer = _printmod(list, format[i + 1], printbuffer, &counter, &j);
			i++;
		}
		else if (special_char == 92)
		{
			counter++;
			printbuffer = _printspecials(format[i + 1], printbuffer, &j);
			i++;
		}
		i++;
	}
	if (printbuffer[0] != '\0')
		pbuffer(printbuffer); /*imprime buffer*/
	va_end(list);
	free(printbuffer);
	return (counter);
}

/**
 * _printspecials - picks a function to print a format input
 * @format: character to compare
 * *@printbuffer: pointer to a buffer
 * *@j: loop counte for printbuffer position
 * Return: Pointer to printbuffer
 */

char *_printspecials(char format, char *printbuffer, int *j)
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
	return (printbuffer);
}
