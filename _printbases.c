#include "holberton.h"

/**
 * p_binary - converts a number into binary
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */
void p_binary(va_list list, int *counter)
{
	int num = va_arg(list, int), size = num, i;
	char *str;

	/* Calculate size of binary num */
	for (i = 0; size >= 1; i++)
		size /= 2;

	size = i;
	*counter += size; /* Add length of number to counter*/

	/* Allocate size memory and validate Null */
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	/* Assign to str the binary calculation */
	for (i = size; i > 0; i--)
	{
		str[i - 1] = (num % 2) + '0';
		num /= 2;
	}
	write(1, str, size);
}

/**
 * p_octal - converts a number into octal
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */
void p_octal(va_list list, int *counter)
{
	int num = va_arg(list, int), size = num, i;
	char *str;

	/* Calculate size of octal number*/
	for (i = 0; size >= 1; i++)
		size /= 8;

	size = i;
	*counter += size;

	/* Allocate size memory and validate Null */
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	/* Assign to str the octal calculation */
	for (i = size; i > 0; i--)
	{
		str[i - 1] = (num % 8) + '0';
		num /= 8;
	}
	write(1, str, size);
}
