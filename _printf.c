#include "holberton.h"
char *_printspecials(char format, char *printbuffer, int *i, int *j);

/**
 * _printf - emulate the function of printf
 * @format: Amount of arguments received
 * Return: 0
*/

int _printf(const char * const format, ...)
{
	va_list list;
	int i = 0, j = 0;
	char special_char;
	char *printbuffer;
	int counter = 0;
	int size = strlen(format);

	va_start(list, format);
	printbuffer = malloc(sizeof(char) * strlen(format));
	if (printbuffer == NULL)
	{
		return(0);
	} 

	if (format == NULL || list == NULL)
		return (0);

	while (format != NULL && i < size)
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
			printbuffer = _printspecials(format[i + 1], printbuffer, &i, &j);
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
	(*i) += 0;
	return (printbuffer);
}
