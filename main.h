#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**

struct arg_printer - Struct for argument printers
@type: The type of argument to print
@printer: The function to print the argument
*/
typedef struct arg_printer
{
char type;
int (*printer)(va_list *);
} arg_printer_t;
int _printf(const char *format, ...);
int print_char(va_list *args);
int print_string(va_list *args);
int print_percent(attribute((unused)) va_list *args);

#endif /* MAIN_H */
