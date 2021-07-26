#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct data_type -  Is the structure of prints
 * @type: output type
 * @data_proto: print prototype
 */

typedef struct data_type{
    char *type;
    void (*data_proto)(va_list);
} data_t;

/**
 * struct char_type -  Is the structure of prints
 * @type: output type
 * @data_proto: print prototype
 */

typedef struct char_type{
    char *type;
    void (*data_proto)(void);
} char_t;

void print_f(const char * const format, ...);

#endif