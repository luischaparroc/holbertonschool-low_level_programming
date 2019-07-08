#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "Helloand, world and universe";
	char *f = "and";
	char *t;

	t = _strstr(s, f);
	printf("%s\n", t);
	return (0);
}
