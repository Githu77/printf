#include "main.h"


/**
 * print_d_i - Prints a decimal integer
 * @args: A va_list containing the integer to print
 *
 * Return: The number of digits printed
 */
int print_d_i(va_list args)
{
	int n = va_arg(args, int), power = 1, result = 0;

	if (n < 0)
	{
		result += _putchar('-');
		n *= -1;
	}

	while ((n / power) >= 10)
		power *= 10;

	while (power > 0)
	{
		result += _putchar(((n / power) % 10) + '0');
		power /= 10;
	}

	return (result);
}

