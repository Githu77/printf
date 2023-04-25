#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct specifier - struct for holding format specifiers and their functions
 * @specifier: the format specifier character
 * @func: the function to handle the specifier
 */
typedef struct specifier
{
    char specifier;
    int (*func)(va_list);
} specifier_t;

/**
 * print_char - function to handle the %c specifier
 * @args: list of arguments passed to the function
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - function to handle the %s specifier
 * @args: list of arguments passed to the function
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    if (!str)
        str = "(null)";
    int len = 0;
    while (*str)
        len += write(1, str++, 1);
    return (len);
}

/**
 * print_integer - function to handle the %d and %i specifiers
 * @args: list of arguments passed to the function
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    char buffer[32];
    int len = snprintf(buffer, 32, "%d", num);
    return (write(1, buffer, len));
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print
 * Return: characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'d', print_integer},
        {'i', print_integer},
        {'\0', NULL}
    };

    va_start(args, format);
    while (*format)
    {
        if (*format++ == '%')
        {
            specifier_t *spec = specifiers;
            while (spec->specifier)
            {
                if (spec->specifier == *format)
                {
                    printed_chars += spec->func(args);
                    break;
                }
                spec++;
            }
        }
        else
            printed_chars += write(1, format - 1, 1);
    }
    va_end(args);
    return (printed_chars);
}

