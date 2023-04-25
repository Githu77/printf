#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				printed_chars += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				for (; *str; str++)
				{
					printed_chars += write(1, str, 1);
				}
			}
			else if (*format == '%')
			{
				printed_chars += write(1, "%", 1);
			}
			else
			{
				printed_chars += write(1, &format[-1], 1);
				printed_chars += write(1, &format[0], 1);
			}
		}
		else
		{
			printed_chars += write(1, format, 1);
		}
	}

	va_end(args);
	return (printed_chars);
}
