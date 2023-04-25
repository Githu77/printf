#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct conversion_specifier - a struct that contains a conversion specifier and its corresponding function
 * @format: the conversion specifier character
 * @func: a pointer to the function that handles the conversion specifier
 */
typedef struct conversion_specifier
{
    char format;
    int (*func)(va_list);
} conv_spec;

int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */

