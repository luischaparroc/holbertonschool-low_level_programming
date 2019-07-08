#include "holberton.h"
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0, j = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c && j == 0)
		{
			j = i;
			break;
		}
	if (j == 0)
		return ('\0');
	return (s + j);
}
