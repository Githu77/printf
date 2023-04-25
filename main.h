#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct conversion_specifier - contains specifier and function
 * @format: specifier character
 * @func: a pointer to function that handles the conversion specifier
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

