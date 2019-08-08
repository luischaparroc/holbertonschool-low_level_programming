#include "holberton.h"
#include <limits.h>

/**
 * print_binary - prints the binary representation
 * of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
	unsigned long long int i;
	int first_one;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	i = (unsigned long long)LONG_MAX + 1;
	first_one = 0;

	for (; i != 0; i >>= 1)
	{
		if (n & i)
		{
			_putchar('1');
			first_one = 1;
		}
		else
		{
			if (first_one == 1)
				_putchar('0');
		}
	}
}
