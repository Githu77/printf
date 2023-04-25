#include "main.h"

/**
 * print_char - Prints a character
 * @arg: A va_list containing a character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
}

/**
 * print_string - Prints a string of characters
 * @arg: A va_list containing a string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int len = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str++);
		len++;
	}

	return (len);
}

/**
 * print_int - Prints an integer
 * @arg: A va_list containing an integer to be printed
 *
 * Return: The number of characters printed
 */
int print_int(va_list arg)
{
	int num = va_arg(arg, int);
	int len = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}

	if (num / 10)
		len += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	len++;

	return (len);
}

/**
 * print_int_helper - Helps print_int print an integer
 * @num: The integer to print
 *
 * Return: The number of digits in the integer
 */
int print_int_helper(int num)
{
	int len = 0;

	if (num / 10)
		len += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	len++;

	return (len);
}

/**
 * _printf - Prints a formatted string
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int (*func)(va_list);
	print_info_t info;

	va_start(args, format);

	while (format && format[printed_chars])
	{
		if (format[printed_chars] == '%')
		{
			printed_chars++;
			if (format[printed_chars] == '\0')
				break;

			func = get_print_func(format[printed_chars]);
			if (func == NULL)
			{
				if (format[printed_chars] != '%')
				{
					_putchar('%');
					printed_chars--;
				}
				else
					_putchar('%');

				printed_chars++;
				continue;
			}

			info = get_print_info(args, format[printed_chars]);
			if (info.length_modifier == LONG || info.length_modifier == LONGLONG)
				info.is_signed = 1;

			printed_chars += func(info.args);
		}
		else
		{
			_putchar(format[printed_chars]);
			printed_chars++;
		}
	}

	va_end(args);

	return (printed_chars);
}

/**
 * get_print_func - Returns the appropriate print function for a specifier
 * @c: The conversion specifier character
 *
 * Return: A pointer to the appropriate print function, or NULL if c is invalid
 */
int (*get_print_func(char c))(va_list)
{
	print_func_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL},
	};
	int i

