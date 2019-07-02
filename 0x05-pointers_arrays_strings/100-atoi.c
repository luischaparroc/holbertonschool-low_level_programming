#include "holberton.h"
#include <stdio.h>
/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
		{
			break;
		}
		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			size++;
			m *= 10;
		}
		count++;
	}
	if (size == 0)
		return (size);

	for (i = count - size; i < count; i++)
	{
		m /= 10;
		oi = oi + ((*(s + i) - 48) * m);
	}
	return (oi * pn);
}
