#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	int c, boolean, boolean2;
	long int n1, n2, fn, fn2, n11, n22;

	n1 = 1;
	n2 = 2;
	boolean =  boolean2 = 1;
	printf("%ld, %ld", n1, n2);
	for (c = 0; c < 96; c++)
	{
		if (boolean)
		{
			fn = n1 + n2;
			printf(", %ld", fn);
			n1 = n2;
			n2 = fn;
		}
		else
		{
			if (boolean2)
			{
				n11 = n1 % 1000000000;
				n22 = n2 % 1000000000;
				n1 = n1 / 1000000000;
				n2 = n2 / 1000000000;
				boolean2 = 0;
			}
			fn2 = (n11 + n22);
			fn = n1 + n2 + (fn2 / 1000000000);
			printf(", %ld", fn);
			printf("%ld", fn2 % 1000000000);
			n1 = n2;
			n11 = n22;
			n2 = fn;
			n22 = (fn2 % 1000000000);
		}
		if (((n1 + n2) < 0) && boolean == 1)
			boolean = 0;
	}
	printf("\n");
	return (0);
}
