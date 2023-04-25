#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print
 * Return: characters printed.
 */
int _print_d_i(const char *format, ...)
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
					char buffer[32];
					int len = snprintf(buffer, 32, "%d", num);
					printed_chars += write(1, buffer, len);
					break;
				}
			}
		}
		else
			printed_chars += write(1, format - 1, 1);
	}
	va_end(args);
	return (printed_chars);
}
