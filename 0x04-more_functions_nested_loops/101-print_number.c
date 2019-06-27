#include "holberton.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */
void print_number(int n)
{
	int boolean, m, count;

	m = n;
	boolean = 1;
	count = 0;
	while (boolean)
	{
		if (m < 0)
		{
			_putchar(45);
			n *= -1;
			m = n;
		}
		while (m > 9)
		{
			m /= 10;
			count += 10;
		}
		_putchar(m + 48);
		if (m == (n % 10))
		{
			break;
		}
		else
		{
			m = n % count;
		}
		count = 0;
	}
}
