#include <stdio.h>

/**
 * main - Prints numbers between 00 to 99.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, e, g, h;

	i = 48;
	e = 48;
	g = 48;
	h = 48;

	while (h < 58)
	{
		g = 48;
		while (g < 58)
		{
			e = 48;
			while (e < 58)
			{
				i = 48;
				while (i < 58)
				{
					putchar(h);
					putchar(g);
					putchar(' ');
					putchar(e);
					putchar(i);
					if (h == 57 && g == 57)
					{
						break;
					}
					putchar(',');
					putchar(' ');
					i++;
				}
				e++;
			}
			g++;
		}	
	}
	putchar('\n');
	return (0);
}
