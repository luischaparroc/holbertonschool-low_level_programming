#include <stdio.h>
#include "3-calc.h"

/**
 * main - check the code for Holberton School students.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int a, b;
	char c;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	c = argv[2][0];

	if ((c != '+' && c != '-' && c != '*' && c != '/' && c != '%') || argv[2][1])
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if (b == 0 && (c == '/' || c == '%'))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(argv[2])(a, b));
	return (0);
}
