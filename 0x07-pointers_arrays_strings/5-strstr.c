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
	unsigned int i, j, ln, bool;

	for (ln = 0; *(needle + ln) != '\0'; ln++)
		;
	for (i = 0; *(haystack + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(needle + j) != '\0'; j++)
		{
			if (*(haystack + j + i) == *(needle + j))
				bool = 0;
			else
			{
				bool = 1;
				i = i + j - 1;
				break;
			}
		}
		if (bool == 0 && j == ln)
			return (haystack + i);
	}
	return (0);
}
