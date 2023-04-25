#include "main.h"

/**
 * print_b - Prints an unsigned integer in binary notation
 * @args: A va_list containing the integer to print
 *
 * Return: The number of digits printed
 */
int print_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), bit_count = 0, result = 0;

	if (n == 0)
		return (_putchar('0'));

	/* Count number of bits */
	for (bit_count = 0; (n >> bit_count) != 0; bit_count++)
		;

	/* Print binary number */
	while (bit_count > 0)
	{
		bit_count--;
		result += _putchar(((n >> bit_count) & 1) + '0');
	}

	return (result);
}

