#include "function_pointers.h"

/**
 * int_index - function that searches for an integer.
 * @array: array to be created
 * @cmp: function to be used to compare values
 * @size: number of elements in the array
 *
 * Return: index of first element which cmp does not return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || cmp == NULL)
{
return (-1);
}

if (size <= 0)
return (-1);

for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
{
return (i);
}
}
return (-1);
}
