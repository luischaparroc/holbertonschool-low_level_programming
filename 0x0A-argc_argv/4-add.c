#include <stdio.h>

/**
 * main - adds positive numbers.
 * @argc: number of command line arguments.
 * @argv: array that contains the program command line arguments.
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int i, add = 0, num;

	for (i = 1; i < argc; i++)
	{
		num = 0;
		while (*(argv + i)[0] != '\0')
		{
			if (*(argv + i)[0] < '0' || *(argv + i)[0] > '9')
			{
				printf("Error\n");
				return (1);
			}
			if (num != 0)
				num *= 10;
			num += (*(argv + i)[0] - '0');
			argv[i]++;
		}
		add += num;
	}
	printf("%d\n", add);
	return (0);
}
