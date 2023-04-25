#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format++ == '%')
		{
			switch (*format++)
			{
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					char buffer[20];
					int i = 0;
					if (num < 0)
					{
						printed_chars += write(1, "-", 1);
						num = -num;
					}
					do {
						buffer[i++] = num % 10 + '0';
						num /= 10;
					} while (num);
					while (--i >= 0)
					{
						printed_chars += write(1, &buffer[i], 1);
					}
					break;
				}
				default:
					printed_chars += write(1, &format[-2], 2);
					break;
			}
		}
		else
			printed_chars += write(1, format - 1, 1);
	}
	va_end(args);
	return (printed_chars);
}

