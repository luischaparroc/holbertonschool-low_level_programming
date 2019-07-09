#include "holberton.h"

/**
 * _strstr - finds the first occurrence of the substring.
 * needle in the string haystack.
 * @haystack: entire string.
 * @needle: substring.
 * Return: pointer to the beginning of located substring or
 * NULL if the substring is not found.
*/
char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0, ln = 0, boolean;

	for (ln = 0; *(needle + ln) != '\0'; ln++)
		;
	for (i = 0; *(haystack + i) != '\0'; i++)
	{
		boolean = 1;
		for (j = 0; *(needle + j) != '\0'; j++)
		{
			if (*(haystack + j + i) == *(needle + j))
				boolean = 0;
			else
			{
				boolean = 1;
				break;
			}
		}
		if (boolean == 0 && j == ln)
			return (haystack + i);
	}
	if (j == ln)
		return (haystack + i);
	return (0);
}
