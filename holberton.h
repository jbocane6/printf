#ifndef PRINTF_H
#define PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * struct data_type -  Is the structure of prints
 * @type: output type
 * @data_proto: print prototype
 */
typedef struct data_type
{
	char *type;
	void (*data_proto)(va_list, int*);
} data_t;

/*_printf - emulate the function of printf */
int _printf(const char * const format, ...);

/* Picks a function to print a format input */
char *_printmod(va_list list, char inpt, char *str, int *count, int *j);

/* Prints and delete chars in buffer */
void pbuffer(char *printbuffer);

/* Prints integers with write */
void p_int(va_list list, int *counter);

/* Prints a char with write*/
void p_char(va_list list, int *counter);

/* Prints strings */
void p_string(va_list list, int *counter);

/* _printspecials - picks a function to print a format input */
char *_printspecials(char format, char *printbuffer, int *j);

/* p_reverse - Prints strings in reverse */
void p_reverse(va_list list, int *counter);

/* p_rot13 - Encodes a string using rot13. */
void p_rot13(va_list list, int *counter);

/* _itoa - converts a number into a string*/
char *_itoa(long number, int *size);

/* p_binary - converts a number into binary */
void p_binary(va_list list, int *counter);

/* p_octal - converts a number into octal */
void p_octal(va_list list, int *counter);

/* p_hexalow - converts a number into hexdecimal lowercase */
void p_hexalow(va_list list, int *counter);

/* p_hexaup - converts a number into hexdecimal uppercase */
void p_hexaup(va_list list, int *counter);

#endif
