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
	int j, k, l;

	if (size <= 0)
		printf("\n");
	else
	{
		for (j = 0; j < size; j += 10)
		{
			printf("%.8x:", j);
			for (k = j; k < j + 10; k++)
			{
				if (k % 2 == 0)
					printf(" ");
				if (k < size)
					printf("%.2x", *(b + k));
				else
					printf("  ");
			}
			printf(" ");
			for (l = j; l < j + 10; l++)
			{
				if (l >= size)
					break;
				if (*(b + l) < 32 || *(b + l) > 126)
					printf("%c", '.');
				else
					printf("%c", *(b + l));
			}
			printf("\n");
		}
	}
}
