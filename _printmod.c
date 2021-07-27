#include "holberton.h"

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
 * p_int - Prints integers.
 * @list: list that contains value
 * to print
 * @counter: counts chars printed
*/

void p_int(va_list list, int *counter)
{
	int i = va_arg(list, int);
	int size = i;
	int mod = 1, j, k = 0;
	char *str;

	if (i < 0)
	{
		i *= -1;
		size = i;
		k = 1;
	}

	for (j = 0; size > 0; j++)
		size /= 10;
	size = j + 1;
	j = 0;

	str = malloc((size + k) * sizeof(char));
	if (str == NULL)
		return;

	for (j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		str[size - 1 - j] = mod + '0';
		i /= 10;
		if (k == 1)
		{
			str[0] = 45;
			k = 0;
		}
	}
	*counter += size;
	write(1, str, size);
}

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
	int len = strlen(str);
	*counter += len;
	write(1, str, len);
}

/**
 * p_rev - Prints string in reverse
 * @list: list that contains value
 * to print
 * @count: counts chars printed
*/
void p_rev(va_list list, int *count)
{
	char *value = "%";
	char *str = va_arg(list, char *);

	if (str == NULL)
		exit(0);

	*count += 2;
	write(1, value, 2);
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
		{"r", p_rev},
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
	if (k >= 4)
	{
		str[*j] = inpt; /*add inpt[i+1] to buffer*/
		*count += 1;
		(*j)++;
	}
	return (str);
}
