#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees the 2d array created by alloc_grid
 * @grid: 2d array created alloc_grid
 * @height: integer
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
int i;
for (i = 0; i < height; i++)
{
free(grid[i]);
}
free(grid);
}
