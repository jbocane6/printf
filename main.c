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
    int len;
    /*int len2 = 11;
    int l = INT_MIN;
    len = abs(l) - 1024; */

    /* _printf("%i", l); */
    len = _printf("%r", "Juan Camilo");
    printf("\n%i\n", len);
    /*len2 = printf("%i", l);
    printf("\n");
    printf("Len:[%d]\n", len2) */;
    /* printf("Len:[%d]\n", len); */
    return (0);
}