#include "main.h"
#include <stdlib.h>

/**
 * *create_array - creates an array of chars.
 * @c: array of chars
 * @size: size of array
 *
 * Return: pointer to the array
 */
char *create_array(unsigned int size, char c)
{
unsigned int i = 0;
char *arr;

if (size == 0)
{
return (NULL);
}

arr = malloc(size * sizeof(char));
if (arr == NULL)
{
return (NULL);
}

while (i < size)
{
arr[i] = c;
i++;
}

return (arr);
}
