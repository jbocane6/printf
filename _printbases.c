#include "holberton.h"
#include <limits.h>

/**
 * p_binary - converts a number into binary
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */

void p_binary(va_list list, int *counter)
{
	long num = va_arg(list, long), size, i;
	char *str, zero = 0;

	if (num == 0)
	{
		write(1, &zero, 1);
		*counter += 1;
		return;
	}

	if (num < 0)
		num = ULONG_MAX + num;
	size = num;

	for (i = 0; size >= 1; i++)
		size /= 2;

	size = i;
	*counter += size;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	for (i = size; i > 0; i--)
	{
		str[i - 1] = (num % 2) + '0';
		num /= 2;
	}
	write(1, str, size);
	free(str);
}

/**
 * p_octal - converts a number into octal
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */

void p_octal(va_list list, int *counter)
{
	long num = va_arg(list, long), size, i;
	char *str, zero = 0;

	if (num == 0)
	{
		write(1, &zero, 1);
		*counter += 1;
		return;
	}

	if (num < 0)
		num = ULONG_MAX + num;
	size = num;

	for (i = 0; size >= 1; i++)
		size /= 8;

	size = i;
	*counter += size;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	for (i = size; i > 0; i--)
	{
		str[i - 1] = (num % 8) + '0';
		num /= 8;
	}
	write(1, str, size);
	free(str);
}

/**
 * p_hexalow - converts a number into hexdecimal lowercase
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */

void p_hexalow(va_list list, int *counter)
{
	long num = va_arg(list, long), size, i;
	char *str, zero = 0;
	char *hexa = "0123456789abcdef";

	if (num == 0)
	{
		write(1, &zero, 1);
		*counter += 1;
		return;
	}

	if (num < 0)
		num = ULONG_MAX + num;
	size = num;

	for (i = 0; size >= 1; i++)
		size /= 16;

	size = i;
	*counter += size;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	for (i = size; i > 0; i--)
	{
		str[i - 1] = hexa[(num % 16)];
		num /= 16;
	}
	write(1, str, size);
	free(str);
}

/**
 * p_hexaup - converts a number into hexdecimal uppercase
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
 */

void p_hexaup(va_list list, int *counter)
{
	long num = va_arg(list, long), size, i;
	char *str, zero = 0;
	char *hexa = "0123456789ABCDEF";

	if (num == 0)
	{
		write(1, &zero, 1);
		*counter += 1;
		return;
	}

	if (num < 0)
		num = ULONG_MAX + num;
	size = num;

	for (i = 0; size >= 1; i++)
		size /= 16;

	size = i;
	*counter += size;

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return;

	for (i = size; i > 0; i--)
	{
		str[i - 1] = hexa[(num % 16)];
		num /= 16;
	}
	write(1, str, size);
	free(str);
}
