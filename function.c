#include "main.h"

/**
* print_char - prints a character
* @args: arguments
* @count: pointer to count chars
*/
void print_char(va_list args, int *count)
{
	putchar(va_arg(args, int));
	(*count)++;
}

/**
* print_string - prints a string
* @args: arguments
* @count: pointer to count chars
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
* print_int - prints an integer
* @args: arguments
* @count: pointer to count chars
*/
void print_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int digit, sign = 1, i = 0;
	char buffer[20];

	if (num < 0)
	{
		sign = -1;
		num *= sign;
	}

	do {
		digit = num % 10;
		buffer[i++] = digit + '0';
		num /= 10;
	} while (num);

	if (sign == -1)
		uffer[i++] = '-';

	while (--i >= 0)
	{
		putchar(buffer[i]);
		(*count)++;
	}
}

/**
* print_percent - prints a percent sign
* @args: arguments
* @count: pointer to count chars
*/
void print_percent(va_list args, int *count)
{
	(void) args;
	putchar('%');
	(*count)++;
}

/**
* _printf - custom printf function
* @format: format string
* Return: the no of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	format_specifier formats[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
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
