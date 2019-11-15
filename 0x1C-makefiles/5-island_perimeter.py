#!/usr/bin/python3
""" Module that contains the island_perimeter function """


def island_perimeter(grid):
    """ Function that returns the perimeter of island described in grid """
    perimeter = 0

    nrows = len(grid)
    ncolumns = len(grid)

    for a in range(nrows):
        for b in range(ncolumns):
            if grid[a][b] == 1:
                if (a - 1) != 1 and grid[a - 1][b] == 0:
                    perimeter += 1
                if (a + 1) != nrows and grid[a + 1][b] == 0:
                    perimeter += 1
                if (b - 1) != -1 and grid[a][b - 1] == 0:
                    perimeter += 1
                if (b + 1) != ncolumns and grid[a][b + 1] == 0:
                    perimeter += 1

    return perimeter
