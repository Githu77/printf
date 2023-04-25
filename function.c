#include "main.h"

/**
 * _function1 - Outputs a formatted string.
 * @format: Character string to print
 * Return: characters printed.
 */
int _function1(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;

            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char buffer[32];
                int i = 0;

                if (num == 0)
                {
                    printed_chars += write(1, "0", 1);
                    continue;
                }

                if (num < 0)
                {
                    printed_chars += write(1, "-", 1);
                    num = -num;
                }

                while (num != 0)
                {
                    buffer[i++] = num % 10 + '0';
                    num /= 10;
                }

                while (i > 0)
                {
                    printed_chars += write(1, &buffer[--i], 1);
                }
            }
            else
            {
                printed_chars += write(1, "%", 1);
                printed_chars += write(1, &(*format), 1);
            }
        }
        else
        {
            printed_chars += write(1, &(*format), 1);
        }

        format++;
    }

    va_end(args);
    return (printed_chars);
}

