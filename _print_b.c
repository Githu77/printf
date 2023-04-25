#include "main.h"

/**
 * print_b - Converts an unsigned int to binary
 * @args: A va_list containing the unsigned int to convert
 *
 * Return: The number of digits printed
 */
int print_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), mask = 1 << 31;
	int result = 0, flag = 0;

	while (mask)
	{
		if (n & mask)
		{
			result += _putchar('1');
			flag = 1;
		}
		else if (flag)
			result += _putchar('0');
		mask >>= 1;
	}
	if (!result)
		result += _putchar('0');

	return (result);
}

