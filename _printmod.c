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
	/* Print content on printbuffer */
	write(1, printbuffer, i);
	/* Clean and initialize printbuffer after printing*/
	for (j = 0; j < i; j++)
		printbuffer[j] = '\0';
}

/**
 * p_intmin - Prints integers whe is equal to INT_MIN.
 * @i: integer received to print
 * @counter: counts chars printed
 * Return: void
*/

void p_intmin(int i, int *counter)
{
	int j, k, size, mod;
	char *str;

	/*Reduce one digit of i, turn into positive assign i to size*/
	k = (INT_MIN % 10) * -1;
	i /= -10;
	size = i;
	/* Calculate the amount of digits of size */
	for (j = 0; size > 0; j++)
		size /= 10;
	/* Add 2 to size, to correct the previous reducction */
	size = j + 2;
	/* Alloc size memory and verify success allocation */
	str = malloc((size) * sizeof(char));
	if (str == NULL)
		return;
	/* Set in str each digit extracted with mod */
	for (j = 0; j < size - 1; j++)
	{
		mod = i % 10;
		str[size - 2 - j] = mod + '0';
		i /= 10;
	}
	/*Set first and last digit with the minus and the number removed*/
	str[0] = '-';
	str[j] = k + '0';
	*counter += size; /* Add to the counter length of the number */
	write(1, str, size + 1); /* Prints the number i*/
	free(str); /* Release allocated memory */
}

/**
 * p_int - Prints integers.
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: Void
*/

void p_int(va_list list, int *counter)
{
	int size = 0;
	int maxmin = va_arg(list, int);
	char *str;

	if (maxmin <= INT_MIN) /* If maxmin is smaller or equal calls a function*/
	{
		p_intmin(maxmin, counter);
		return;
	}
	str = _itoa(maxmin, &size); /* Calls a function to convert num into str*/
	*counter += size; /* Add to the counter length of the number  to counter */
	write(1, str, size); /* Prints the number i*/
	free(str); /* Release allocated memory */
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

	/* Save negative sign of number and turn into positive assign i to size*/
	if (number <= 0)
	{
		if (number < 0)
			k = 1;
		number *= -1;
		j = 1;
	}
	*size = number; /* Assign original variable to the pointer */
	/* Calculate the size by counting the digits*/
	for (; *size > 0; j++)
		*size /= 10;
	*size = j;
	/* Alloc j size memory and verify success allocation */
	str = malloc(sizeof(char) * j);
	if (str == NULL)
		return (NULL);

	/* Assign the last digit into the right position in string */
	for (; j > 0; j--)
	{
		str[j - 1] = (number % 10) + '0';
		number /= 10;
	}
	/*Set first digit with the minus if k indicates negative num */
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
	data_t datas[] = {{"c", p_char}, {"s", p_string}, {"d", p_int}, {"i", p_int},
		{"r", p_reverse}, {"R", p_rot13}, {"b", p_binary}, {NULL, NULL}};

	while (k < 7) /*Search for coincidence into the structure*/
	{
		if (datas[k].type[0] == inpt)
		{
			pbuffer(str);
			(*j) = 0; /* Move j pinter to buffer to its initial position  */
			datas[k].data_proto(list, count); /* Send args to the function*/
			break;
		}
		k++;
	}
	if (k >= 7)  /* Case character if not a modifier add inpt[i+1] to str */
	{
		if (inpt == '%')
		{
			str[*j] = inpt;
			*count += 1;
			(*j)++;
		}
		else /* Add % and non modifier char & sum counter for each char*/
		{
			str[*j] = '%';
			(*j)++;
			str[*j] = inpt;
			*count += 2;
			(*j)++;
		}
	}
	return (str); /* Return buffer */
}
