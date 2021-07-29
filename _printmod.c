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

	/* Calculate printbuffer length*/
	for (i = 0; printbuffer[i] != '\0'; i++)
		;
	write(1, printbuffer, i); /* print all characters */
	/* Clean printbuffer after printing*/
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
	/* Assign value of INT_MIN reduced in the last digit and positive */
	k = (INT_MIN % 10) * -1;
	/* Take the variable and reduce it the last digit and becomeing it positive */
	i /= -10;
	size = i;/* Asigned i to size to get the amount of digits */
	/* Calculate the amount of digits of the shorten int */
	for (j = 0; size > 0; j++)
		size /= 10;
	/* The number was reduced one digit and is positive, add 2 spaces to size */
	size = j + 2;
	str = malloc((size) * sizeof(char));/* Asigning memory to the new array */
	if (str == NULL)
		return;

	for (j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		/* Store the module of the división in the place it belongs */
		str[size - 2 - j] = mod + '0';
		i /= 10;/* Reduce i in one digit */
	}
	str[0] = '-';/* When finished, add minus as the first char */
	/* In the last position adds the digit removed at the begin */
	str[j] = k + '0';
	/* Increasing the count of chars in the same amount of digits */
	*counter += size;
	write(1, str, size);/* Write the number converted to string */
	free(str);/* Free memory */
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
	/* If the number is smaller or equal call the function */
	if (maxmin <= INT_MIN)
	{
		p_intmin(maxmin, counter);/* Send the number and the counter */
		return;
	}
	/* Call a function that converts number to string */
	str = _itoa(maxmin, &size);
	/* Increasing the count of chars in the same amount of size */
	*counter += size;
	write(1, str, size);/* Write the string received */
	free(str);/* Free memory */
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
		/* If the number is less than 0 asigned a value to remind to add a - */
		if (number < 0)
			k = 1;
		number *= -1;/* Become positive the number */
		/* Inicialize the variable to 1 for a slot additional for the - or 0 */
		j = 1;
	}
	/* know the size, asigned to the original variable through the pointer */
	*size = number;

	for (; *size > 0; j++)
		*size /= 10;/* Calculate the size by counting the digits */
	/* know the size, asigned to the original variable through the pointer */
	*size = j;
	str = malloc(sizeof(char) * j);/* Asigning memory to the string */
	if (str == NULL)
		return (NULL);

	for (; j > 0; j--)
	{
		/* take the last digit and assign it to the righ position in string */
		str[j - 1] = (number % 10) + '0';
		number /= 10;/* Reduce number in one digit */
	}
	if (k == 1)
		str[j] = '-';/* If the original number was negative, add ' as first char */
	return (str);/* Return the new string */
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
	data_t datas[] = {{"c", p_char}, {"s", p_string}, {"d", p_int}, {"i", p_int},
		{"r", p_reverse}, {"R", p_rot13}, {"b", p_binary}, {"o", p_octal},
		{"x", p_hexalow}, {"X", p_hexaup}, {NULL, NULL}};

	while (k < 10) /*Search for coincidence into the structure*/
	{
		/* If the caracter is found in the array of structures */
		if (datas[k].type[0] == inpt)
		{
			pbuffer(str);/* Call the function to print all the chars added before */
			/* Return j to its initial position to reallocate the next chars */
			(*j) = 0;
			datas[k].data_proto(list, count);/* Send args to the function that points */
			break;
		}
		k++;
	}
	if (k >= 10)  /* Case character is not a modifier, so add inpt[i+1] to str */
	{
		if (inpt == '%')
		{
			str[*j] = inpt;
			*count += 1;/* As there was 1 char added, we add 1 to count */
			(*j)++;/* As there was 1 char added, we add 1 to position */
		}
		else
		{
			str[*j] = '%';/* Add first the char % and then the char next */
			(*j)++;
			str[*j] = inpt;
			*count += 2; /* As there were 2 chars added, we add 2 to count */
			(*j)++;
		}
	}
	return (str); /* Return buffer */
}
