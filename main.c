#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%d", INT_MIN);
	len2 = printf("%d", INT_MIN);
	printf("\n%d\n", len + len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}