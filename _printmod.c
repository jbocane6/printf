#include "holberton.h"
#include <limits.h>

/**
 * pbuffer - Function that prints and delete chars in buffer.
 * @printbuffer: string to print
 * Return: void
*/
void pbuffer(char *printbuffer)
{
	unsigned int i, j;

	/* Calculate printbuffer length and print each character*/
	for (i = 0; printbuffer[i] != '\0'; i++)
		;
	write(1, printbuffer, i);
	/* Clean and initialize printbuffer after printing*/
	for (j = 0; j < i; j++)
		printbuffer[j] = '\0';
}

/**
 * p_intmin - Prints an integer equal to INT_MIN.
 * @i: integer received to print
 * @counter: counts chars printed
 * Return: void
*/
void p_intmin(int i, int *counter)
{
	int j, k, size, mod;
	char *str;
	/*Extract the last digit*/
	k = (INT_MIN % 10) * -1;
	i /= -10;
	size = i;

	/* Calculates length of i */
	for (j = 0; size > 0; j++)
		size /= 10;
	size = j + 2;
	/* Alloc (size + 1) memory and verify success allocation*/
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
	{
		return;
	}
	/* Set at str each digit of i*/
	for (j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		str[size - 2 - j] = mod + '0';
		i /= 10;
	}
	/*Set first and last digit*/
	str[0] = '-';
	str[j + 1] = k + '0';
	*counter += size; /* Add to the counter length of the number */
	write(1, str, size + 1); /* Prints the number i */
	free(str); /* Release allcated memory */
}

/**
 * p_int - function that prints integers and counts it.
 * @list: list that contains values to print
 * @counter: counts printed chars
 * Return: void
*/
void p_int(va_list list, int *counter)
{
	double maxmin = va_arg(list, double);
	int i, size, mod = 1, j, k = 0;
	char *str;

	if (maxmin <= INT_MIN || maxmin >= INT_MAX) /*int cases max & min length*/
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
	for (j = 0; size > 0; j++)  /* Calculates length of size */
		size /= 10;
	size = j;
	if (j == 0)
		size = 1;
	/* Alloc (size + k) memory and verify success allocation*/
	str = malloc((size + k) * sizeof(char));
	if (str == NULL)
		return;
	/* Set at str each digit of i*/
	for (j = 0; j < size; j++)
	{
		mod = i % 10;
		str[size - j + k - 1] = mod + '0';
		i /= 10;
	}
	/* Set signal of i in negative case*/
	if (k == 1)
		str[0] = 45;
	*counter += size + k;
	write(1, str, size + k); /* Prints the full number */
	free(str); /* Release allocated memory */
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
		{"R", p_rot13},
		{NULL, NULL}};

	while (k < 6) /*Search for coincidence into the structure*/
	{
		if (datas[k].type[0] == inpt)
		{
			pbuffer(str);
			datas[k].data_proto(list, count);
			(*j) = 0;
			break;
		}
		k++;
	}
	if (k >= 6)  /* Case character it not a modifier add inpt[i+1] to str */
	{
		if (inpt == '%')
		{
			str[*j] = inpt;
			*count += 1;
			(*j)++;
		}
		else
		{
			str[*j] = '%';
			(*j)++;
			str[*j] = inpt;
			*count += 2;
			(*j)++;
		}
	}
	return (str);
}
