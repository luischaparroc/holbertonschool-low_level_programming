#include "holberton.h"

/**
 * _puts - prints a string, followed by a new line.
 * @str: input string.
 * Return: no return.
 */
void _puts(char *str)
{
	int count = 0;
	char ch;

	while (count >= 0)
	{
		ch = str[count];
		if (ch == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(ch);
		count++;
	}
}
