#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);
int print_d_i(va_list args);
int print_b(va_list args);

#endif /* MAIN_H */
