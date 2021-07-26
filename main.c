#include "printf.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int len;
	int len2;
	len = print_f("camilo %%c sol %d\nbogota \n%s", 'H', 253, "lberton");
	len2 = printf("camilo %c sol %d\nbogota \n%s", 'H', 253, "lberton");
	printf("\n%d\n", len);
	printf("\n%d\n", len2);
	return (0);
}
