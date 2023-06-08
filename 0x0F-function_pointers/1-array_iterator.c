#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - executes a function given as a parameter on each element of
 * an array.
 * @array: array to be created
 * @action: pointer to the function to be used
 * @size: size of the array
 *
 * Return: Nothing.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i = 0;
if (action == NULL || array == NULL)
{
return;
}

while (i < size)
{
action(array[i]);
i++;
}
}
