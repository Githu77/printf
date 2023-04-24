#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/**
*struct format_specifier - specifies format
*@specifier: char that specify
*@print_func: prints contents
*/

typedef struct format_specifier
{
	char specifier;
	void (*print_func)(va_list args, int *count);
} format_specifier;

int _printf(const char *format, ...);

#endif
