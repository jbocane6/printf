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
    int len = 11;
    int len2 = 11;

    /* len = _printf("%d", INT_MIN);
    printf("\n");
    len2 = printf("%d", INT_MIN);
    printf("\n"); */
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}