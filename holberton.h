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

/*print_f - emulate the function of printf */
int print_f(const char * const format, ...);

/* Picks a function to print a format input */
char *_printmod(va_list list, char inpt, char *str, int *count, int *j);

/* Prints and delete chars in buffer */
void pbuffer(char *printbuffer);

/* Prints integers with write */
void p_int(va_list list, int *counter);

/* Prints an only char  with write*/
void p_char(va_list list, int *counter);

/* Prints strings */
void p_string(va_list list, int *counter);

/* _printspecials - picks a function to print a format input */
char *_printspecials(char format, char *printbuffer, int *i, int *j);

#endif
