#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct specifier - struct for format specifier
 * @type: type of specifier
 * @print_func: handles the specifier
 */
typedef struct specifier
{
	char type;
	int (*print_func)(va_list);
} specifier_t;

int _printf(const char *format, ...);

#endif
