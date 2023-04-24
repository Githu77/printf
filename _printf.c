#include "main.h"


/**
* print_char - prints a char
* @args: arguments
* @count: chars printed
*/
void print_char(va_list args, int *count)
{
	putchar(va_arg(args, int));
	(*count)++;
}

/**
* print_string - prints a string
* @args: arguments
* @count: chars printed
*/

void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	while (*str)
	{
		putchar(*str++);
		(*count)++;
	}
}

/**
* print_percent - prints a percent
* print_char - prints character
* @args: arguments
* @count: chars printed
*/

void print_percent(va_list args, int *count)
{
	(void)args;
	putchar('%');
	(*count)++;
}

/**
* _printf - printf function
* @format: format string
* Return: chars printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	format_specifier formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; formats[i].print_func; i++)
			{
				if (*format == formats[i].specifier)
				{
					formats[i].print_func(args, &count);
					break;
				}
			}
		}
		else
		{
			putchar(*format++);
			count++;
		}
	}

	va_end(args);
	return (count);
}
