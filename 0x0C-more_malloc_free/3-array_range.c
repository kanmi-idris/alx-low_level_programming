#include "main.h"
#include <stdlib.h>

/**
 *array_range - function that creates an array of integers.
 *@min: minimum integer in the array
 *@max: maximum integer in the array
 *
 *Return: pointer to the allocated memory
 */
int *array_range(int min, int max)
{
int *array;
int i;

if (min > max)
return (NULL);

array = malloc((max - min + 1) * sizeof(int));
if (!array)
return (NULL);

for (i = 0; i <= max - min; i++)
{
array[i] = min + i;
}

return (array);
}
