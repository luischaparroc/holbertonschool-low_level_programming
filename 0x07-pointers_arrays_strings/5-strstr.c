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
	unsigned int i, j, lh, ln, bool;

	for (lh = 0; *(haystack + lh) != '\0'; lh++)
		;
	for (ln = 0; *(needle + ln) != '\0'; ln++)
                ;
	for (i = 0; i < lh; i++)
	{
		bool = 1;
		for (j = 0; j < ln; j++)
		{
			if (*(haystack + j + i) == *(needle + j))
				bool = 0;
			else
			{
				bool = 1;
				i += j;
				break;
			}
		}
		if (bool == 0)
			return (haystack + i);
	}
	return (0);
}
