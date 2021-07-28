#include "holberton.h"

/**
 * _printf - Function that prints an output according to a input format.
 * @format: Amount of arguments received
 * Return: -1 if null inputs, otherwise counter of printed characters
*/
int _printf(const char * const format, ...)
{
	va_list list;
	int i = 0, j = 0, counter = 0, size = 0;
	char special_char, *printbuffer;
	/* Verify NULL input cases */
	if (format == NULL || list == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(list, format);
	size = strlen(format);
	/* Alloc format size memory and verify success allocation */
	printbuffer = malloc(sizeof(char) * size);
	if (printbuffer == NULL)
		return (-1);
	/* Look over format content to find '%' and '/' characters */
	for (i = 0; i < size; i++)
	{
		special_char = format[i];

		if (special_char != '%' && special_char != 92)
		{
			counter++;
			printbuffer[j] = format[i]; /* Add values different from '%' and '/' */
			j++;
		}
		else if (special_char == '%') /* Send next char to find matching modifiers */
		{
			printbuffer = _printmod(list, format[i + 1], printbuffer, &counter, &j);
			i++;
		}
		else if (special_char == 92) /* Send next char to find matching modifiers */
		{
			counter++;
			printbuffer = _printspecials(format[i + 1], printbuffer, &j);
			i++;
		}
	}
	if (printbuffer[0] != '\0')
		pbuffer(printbuffer); /* Prints buffer */
	va_end(list);
	free(printbuffer);
	return (counter);
}

/**
 * _printspecials - picks a function to print a format input
 * @format: character to compare
 * *@printbuffer: pointer to a buffer
 * *@j: loop counter for printbuffer position
 * Return: Pointer to printbuffer
 */

char *_printspecials(char format, char *printbuffer, int *j)
{
	char *speciallist = "ntbfvr"; /*String of special modifiers*/
	int k = 0;
	/*Look over matching input and special modifiers*/
	while (speciallist[k] != '\0')
	{
		if (speciallist[k] == format)
		{
			printbuffer[*j] = 92 + format; /* Prints buffer*/
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
