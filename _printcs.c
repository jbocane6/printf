#include "holberton.h"

/**
 * p_char - Prints a char.
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
*/
void p_char(va_list list, int *counter)
{
	char i = va_arg(list, int);
	*counter += 1;
	write(1, &i, 1);
}

/**
 * p_string - Prints strings.
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
*/
void p_string(va_list list, int *counter)
{
	char *str = va_arg(list, char *);
	char *nul = "(null)";
	int len = 6;

	if (str == NULL)/* if str is NULL, prints (null) and increase counter in 6 */
	{
		write(1, nul, len);
		*counter += 6;
	}
	else
	{
		len = strlen(str);
		*counter += len;/* Increase counter in the amount of char of the string */
		write(1, str, len);
	}
}

/**
 * p_reverse - Prints strings in reverse.
 * @list: list that contains value to print
 * @counter: counts chars printed
 * Return: void
*/
void p_reverse(va_list list, int *counter)
{
	char *str = va_arg(list, char *);
	int len = strlen(str), i;
	char *rts = malloc(sizeof(char) * len);

	if (rts == NULL)
		return;

	for (i = 0; i < len; i++)
		rts[i] = str[len - 1 - i];/* Rewrites the string in reverse */

	*counter += i;/* Increase counter in the amount of char of the string */
	write(1, rts, i);
	free(rts);/* Free memory */
}

/**
 * p_rot13 - Encodes a string using rot13.
 * @list: list that contains value to encode
 * @counter: counts chars printed
 * Return: void
*/
void p_rot13(va_list list, int *counter)
{
	char *str = va_arg(list, char *), *rts;
	int i, j, len = strlen(str);

	/* Create 2 strings with each value and their correspondent value in Rot13 */
	char str1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !_-,;?"};
	char str2[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm !_-,;?"};

	if (str == NULL)
		return;
	/* Creates a new string with the same size of the original */
	rts = malloc(sizeof(char) * len);
	if (rts == NULL)
		return;

	for (i = 0; str[i] != '\0'; i++)/* Move through the original string */
	{
		/* Move through the string of values without convert*/
		for (j = 0; str1[j] != '\0'; j++)
		{
			if (str[i] == str1[j])
			{
				/* Assign the converted char to the new string in the same position */
				rts[i] = str2[j];
				break;
			}
		}
	}
	*counter += i;/* Increase counter in the amount of char of the string */
	write(1, rts, i);
	free(rts);/* Free memory */
}
