#include "main.h"

void clear_printf_args(va_list args, buffer_t *output);
int execute_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * clear_printf_args - Cleans up arguments passed to _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void clear_printf_args(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * execute_printf - Processes the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int execute_printf(const char *format, va_list args, buffer_t *output)
{
	int i, width, precision, result = 0;
	char temp;
	unsigned char flags, length;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		length = 0;
		if (*(format + i) == '%')
		{
			temp = 0;
			flags = handle_flags(format + i + 1, &temp);
			width = handle_width(args, format + i + temp + 1, &temp);
			precision = handle_precision(args, format + i + temp + 1,
					&temp);
			length = handle_length(format + i + temp + 1, &temp);

			f = handle_specifiers(format + i + temp + 1);
			if (f != NULL)
			{
				i += temp + 1;
				result += f(args, output, flags, width, precision, length);
				continue;
			}
			else if (*(format + i + temp + 1) == '\0')
			{
				result = -1;
				break;
			}
		}
		result += _memcpy(output, (format + i), 1);
		i += (length != 0) ? 1 : 0;
	}
	clear_printf_args(args, output);
	return (result);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int result;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	result = execute_printf(format, args, output);

	return (result);
}

