#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format.
 * @format: format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;

	va_start(list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char *);

				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					write(1, str, 1);
					str++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
			else
			{
				write(1, &format[-1], 1);
				write(1, &format[0], 1);
				printed_chars += 2;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}

		format++;
	}

	va_end(list);

	return (printed_chars);
}
