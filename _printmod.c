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
	int size = 0;
	int maxmin = va_arg(list, int);
	char *str;
	
	if (maxmin <= INT_MIN || maxmin >= INT_MAX)
	{
		p_intmin(maxmin, counter);
		return;
	}
	str = _itoa(maxmin, &size);
	*counter += size;
	write(1, str, size);
	free(str);
}

/**
 * _itoa - converts a number into a string
 * @number: number to convert
 * @size: pointer to size of new array
 * Return: string
 */

char *_itoa(long number, int *size)
{
	long  j = 0, k = 0;
	char *str;

	if (number <= 0)
	{
		if (number < 0)
			k = 1;
		number *= -1;
		j = 1;
	}
	*size = number;

	for (; *size > 0; j++)
		*size /= 10;
	*size = j;
	str = malloc(sizeof(char) * j);
	if (str == NULL)
		return (NULL);

	for (; j > 0; j--)
	{
		str[j - 1] = (number % 10) + '0';
		number /= 10;
	}
	if (k == 1)
		str[j] = '-';
	return (str);
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
