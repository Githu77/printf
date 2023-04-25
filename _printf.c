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
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(args, int);
					printed_chars += write(1, &c, 1);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
					{
						printed_chars += write(1, str, 1);
						str++;
					}
					break;
				}
				case '%':
					printed_chars += write(1, "%", 1);
					break;
				default:
					printed_chars += write(1, &format[-1], 2);
					break;
			}
			format++;
		}
		else
		{
			printed_chars += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (printed_chars);
}
