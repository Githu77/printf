#include "main.h"

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
			printed_chars += _putchar(format[i]);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			printed_chars += _putchar('%');
			i++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case 'c':
					printed_chars += print_c(args);
					break;
				case 's':
					printed_chars += print_s(args);
					break;
				case '%':
					printed_chars += print_percent(args);
					break;
				case 'd':
				case 'i':
					printed_chars += print_d_i(args);
					break;
				case 'b':
					printed_chars += print_b(args);
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(format[i + 1]);
			}
			i++;
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}

