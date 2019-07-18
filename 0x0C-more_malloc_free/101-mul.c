#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _comp_ln - determines bigger number for malloc.
 * @n1: first number.
 * @n2: second number.
 *
 * Return: bigger number for malloc.
 */
int _comp_ln(int n1, int n2)
{
	int nout;

	if (n1 > n2)
		nout = n1 + 1;
	else
		nout = n2 + 1;
	return (nout);
}
/**
 * _checknum - determines length of the number
 * and checks if number is in base 10.
 * @argv: arguments vector.
 * @n: row of the array.
 *
 * Return: length of the number.
 */
int _checknum(char *argv[], int n)
{
	int ln;

	for (ln = 0; argv[n][ln]; ln++)
		if (argv[n][ln] < '0' || argv[n][ln] > '9')
		{
			printf("Error\n");
			exit(98);
		}

	return (ln);
}

/**
 * main - Entry point.
 * program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int ln1, ln2, lnout, add, addl, i, j, k;
	char *nout;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	ln1 = _checknum(argv, 1);
	ln2 = _checknum(argv, 2);
	lnout = _comp_ln(ln1, ln2);
	nout = malloc(lnout + 1);
	nout[lnout] = '\0';
	for (k = lnout - 1, i = ln1 - 1, j = ln2 - 1, addl = 0; k >= 0; k--, i--, j--)
	{
		if (k == 0 && addl == 0 && i < 0 && j < 0)
		{
			free(nout);
			k = lnout - 1;
			nout = malloc(k + 1);
			nout[k] = '\0';
			i = ln1 - 1;
			j = ln2 - 1;
			k--;
		}
		if (i >= 0 && j >= 0)
			add = (argv[1][i] - '0') + (argv[2][j] - '0') + addl;
		else if (i >= 0)
			add = (argv[1][i] - '0') + addl;
		else if (j >= 0)
			add = (argv[2][j] - '0') + addl;
		else
			add = addl;
		addl = add / 10;
		add = add % 10;
		nout[k] = add + '0';
	}
	printf("%s\n", nout);
	return (0);
}
