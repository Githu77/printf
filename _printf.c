#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;  /* move past the '%' character */
            switch (*format)
            {
                case 'c':
                    count += write(1, va_arg(args, int *), 1);
                    break;

                case 's':
                    count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
                    break;

                case '%':
                    count += write(1, "%", 1);
                    break;

                default:
                    /* unsupported conversion specifier, do nothing */
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return count;
}

