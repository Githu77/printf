#include <stdarg.h>
#include <unistd.h>
/**
* _printf - prints according to a format.
* @format: format string
* Return: no of characters printed
*/
int _printf(const char *format, ...)
{int printed_chars = 0;
	va_list list;
	va_start(list, format);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(list, int);

				printed_chars += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char *);
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
	va_end(list);
	return (printed_chars);
}
