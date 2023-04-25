#include "main.h"

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print
 *
 * Return: The number of characters printed
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
				case 'c':
				{
					char c = va_arg(args, int);
					printed_chars += _putchar(c);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
						printed_chars += _putchar(*str++);
					break;
				}
				case 'b':
				{
					printed_chars += print_b(args);
					break;
				}
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					printed_chars += _putchar(*--format);
					break;
			}
		}
		else
			printed_chars += _putchar(*(format - 1));
		format++;
	}
	va_end(args);
	return (printed_chars);
}

