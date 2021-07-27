#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("%c %s", 'A', "Testing Change");
	printf("\n");
	_printf("%d", _printf(NULL));
	printf("\n");
	printf("%d", _printf(NULL));
	printf("\n");
	_printf(NULL);
	printf("\n");
	return (0);
}
