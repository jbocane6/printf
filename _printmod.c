#include "holberton.h"
#include <limits.h>

/**
 * pbuffer - Function #1: Prints and delete chars in buffer.
 * @printbuffer: string to print
*/

void pbuffer(char *printbuffer)
{
	unsigned int i, j;

	for (i = 0; printbuffer[i] != '\0'; i++)
		;
	write(1, printbuffer, i);
	for (j = 0; j < i; j++)
		printbuffer[j] = '\0';
}

/**
 * p_intmin - Prints integers whe is equal to INT_MIN.
 * @i: integer received to print
 * @counter: counts chars printed
*/

void p_intmin(int i, int *counter)
{
	int j, k, size, mod;
	char *str;

	k = (INT_MIN % 10) * -1;
	i /= -10;
	size = i;

	for (j = 0; size > 0; j++)
		size /= 10;
	size = j + 2;

	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
	{
		return;
	}
	for (j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		str[size - 2 - j] = mod + '0';
		i /= 10;
	}
	str[0] = '-';
	str[j + 1] = k + '0';
	*counter += size;
	write(1, str, size + 1);
	free(str);
}

/**
 * p_int - Prints integers.
 * @list: list that contains value
 * to print
 * @counter: counts chars printed
*/

void p_int(va_list list, int *counter)
{
		double maxmin = va_arg(list, double);
	int i, size, mod = 1, j, k = 0;
	char *str;

	if (maxmin <= INT_MIN || maxmin >= INT_MAX)
	{
		p_intmin(maxmin, counter);
		return;
	}

	if (maxmin > INT_MIN || maxmin < INT_MAX)
		i = size = (int)maxmin;
	if (i < 0)
	{
		i = -i;
		size = i;
		k = 1;
	}
	for (j = 0; size > 0; j++)
		size /= 10;

	size = j;
	if (j == 0)
		size = 1;

	str = malloc((size + k) * sizeof(char));
	if (str == NULL)
		return;

	for (j = 0; j < size; j++)
	{
		mod = i % 10;
		str[size - j + k - 1] = mod + '0';
		i /= 10;
	}
	if (k == 1)
		str[0] = 45;
	*counter += size + k;
	write(1, str, size + k);
	free(str);
}

/**
 * _printmod - picks a function to print a format input
 * @list:  argument list
 * @inpt: character to compare
 * *@str: pointer to a printbuffer
 * @count: counts chars printed
 * *@j: loop counter for printbuffer position
 * Return: Pointer to str
 */

char *_printmod(va_list list, char inpt, char *str, int *count, int *j)
{
	int k = 0;
	data_t datas[] = {
	    {"c", p_char},
	    {"s", p_string},
	    {"d", p_int},
	    {"i", p_int},
		{"r", p_reverse},
	    {NULL, NULL}};

	while (k < 5)
	{
		if (datas[k].type[0] == inpt)
		{
			pbuffer(str); /*imprime buffer*/
			datas[k].data_proto(list, count);
			(*j) = 0;
			break;
		}
		k++;
	}
	if (k >= 5)
	{
		if (inpt == '%')
		{
			str[*j] = inpt; /*add inpt[i+1] to buffer*/
			*count += 1;
			(*j)++;
		}
		else
		{
			str[*j] = '%'; /*add inpt[i+1] to buffer*/
			(*j)++;
			str[*j] = inpt; /*add inpt[i+1] to buffer*/
			*count += 2;
			(*j)++;
		}
	}
	return (str);
}
