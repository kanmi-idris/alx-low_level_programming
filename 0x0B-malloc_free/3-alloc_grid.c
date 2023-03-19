#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: integer
 * @height: integer
 *
 * Return: 2 dimensional array of integers
 */
int **alloc_grid(int width, int height)
{
int **arr, i, j;

if (width < 1 || height < 1)
return (NULL);

arr = malloc(sizeof(int *) * height);
if (!arr)
return (NULL);

arr = malloc(sizeof(int) * width);

for (i = 0; i < height; i++)
{
arr[i] = malloc(sizeof(int) * width);
if (!arr[i])
{
for (j = 0; j < i; j++)
{
free(arr[j]);
}
free(arr[i]);
return (NULL);
}
for (j = 0; j < width; j++)
{
arr[i][j] = 0;
}
}

return (arr);
}
