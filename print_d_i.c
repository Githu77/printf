#include "main.h"
#include <stdarg.h>
/**
 * print_d_i - prints an integer
 *
 * @args: arguments list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_d_i(va_list args)
{
        int n, result = 0;
        int power = 1, i;
        char buffer[1];

        n = va_arg(args, int);
        if (n < 0) {
                result += write(1, "-", 1);
                n = -n;
        }
        while ((n / power) > 9)
                power *= 10;
        for (i = power; i > 0; i /= 10) {
                buffer[0] = ((n / i) % 10) + '0';
                result += write(1, buffer, 1);
        }
        return (result);
}

