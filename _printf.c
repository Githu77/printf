#include "main.h"

/**
 * print_char - prints a single character to stdout
 * @args: a va_list containing the character to print
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_str - prints a string to stdout
 * @args: a va_list containing the string to print
 *
 * Return: the number of characters printed
 */
int print_str(va_list args)
{
	int printed_chars = 0;

    char *str = va_arg(args, char *);
    if (!str)
        str = "(null)";
    while (*str)
        printed_chars += write(1, str++, 1);
    return (printed_chars);
}

/**
 * print_percent - prints a single percent character to stdout
 * @args: a va_list (unused)
 *
 * Return: the number of characters printed
 */
int print_percent(va_list args)
{
    (void) args;
    return (write(1, "%", 1));
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	conv_spec specs[] = {
        {'c', print_char},
        {'s', print_str},
        {'%', print_percent},
        {'\0', NULL}
    };
    
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format++ == '%')
        {
            int i = 0;
            while (specs[i].format != '\0' && specs[i].format != *format)
                i++;

            if (specs[i].func != NULL)
                printed_chars += specs[i].func(args);
            else
            {
                printed_chars += write(1, &format[-2], 2);
                if (*format != '\0')
                    printed_chars += write(1, format, 1);
            }
        }
        else
            printed_chars += write(1, format - 1, 1);
    }

    va_end(args);
    return (printed_chars);
}

