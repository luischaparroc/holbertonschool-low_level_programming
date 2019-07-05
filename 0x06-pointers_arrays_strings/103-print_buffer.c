#include "holberton.h"
#include <stdio.h>
/**
 * print_buffer - prints a buffer
 * @b: buffer.
 * @size: size of buffer.
 * Return: no return.
 */

void print_buffer(char *b, int size)
{
	int i, j, k, l;
	char printable[size];

	if (size <= 0)
		printf("\n");
	else
	{
		for (i = 0; i < size; i++)
		{
			if (*(b + i) < 32 || *(b + i) > 126)
				printable[i] = '.';
			else
				printable[i] = *(b + i);
		}

		for (j = 0; j < size; j += 10)
		{
			printf("%08x", j);
			for (k = j; k < j + 10; k++)
			{
				if (k % 2 == 0)
					printf(" ");
				if (k < size)
					printf("%02x", *(b + k));
				else
					printf("  ");
			}
			printf(" ");
			for (l = j; l < j + 10 && l < size; l++)
				printf("%c", printable[l]);
			printf("\n");
		}
	}
}
