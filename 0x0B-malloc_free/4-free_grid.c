#include "holberton.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid.
 * @height: height of the grid.
 *
 * Return: no return
 */
void free_grid(int **grid, int height)
{
	for (height--; height >= 0; height--)
		free(grid[height]);
	free(grid);
}
