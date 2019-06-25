#include "holberton.h"

/**
 * print_last_digit - Prints the last digit
 * of a number.
 *
 * @i: input number as an integer.
 *
 * Return: last digit.
 */
int print_last_digit(int i)
{
	int l;

	if (i < 0)
	{
		i *= -1;
	}
	l = i % 10;
	_putchar(l + '0');
	return (l);
}
