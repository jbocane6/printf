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

typedef structure data_type{
    char *type;
    void (*data_proto)(va_list)
} data_t;

#endif