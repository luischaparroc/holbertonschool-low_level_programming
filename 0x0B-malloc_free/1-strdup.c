#include "holberton.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	char *strout;
	unsigned int i, j;

	if (*str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strout = malloc(sizeof(char) * (i + 1));

	if (strout == NULL)
	{
		free(strout);
		return (NULL);
	}

	for (j = 0; j < i; j++)
		strout[j] = str[j];

	return (strout);
}
