#include "holberton.h"

/**
 * p_char - Prints an only char.
 * @list: list that contains value
 * to print
 * @counter: counts chars printed
*/
void p_char(va_list list, int *counter)
{
	char i = va_arg(list, int);
	*counter += 1;
	write(1, &i, 1);
}

/**
 * p_string - Prints strings.
 * @list: list that contains value
 * to print
 * @counter: counts chars printed
*/
void p_string(va_list list, int *counter)
{
	char *str = va_arg(list, char *);
	char *nul = "(null)";
	int len = 6;

	if (str == NULL)
	{
		write(1, nul, len);
		*counter += 6;
	}
	else
	{
		len = strlen(str);
		*counter += len;
		write(1, str, len);
	}
}

/**
 * p_reverse - Prints strings in reverse.
 * @list: list that contains value
 * to print
 * @counter: counts chars printed
*/
void p_reverse(va_list list, int *counter)
{
	char *str = va_arg(list, char *);
	int len = strlen(str), i;
	char *rts = malloc(sizeof(char) * len);

	if (rts == NULL)
		return;

	for (i = 0; i < len; i++)
		rts[i] = str[len - 1 - i];

	*counter += len;
	write(1, rts, len);
}
