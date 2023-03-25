#include "main.h"
#include <stdlib.h>

/**
*calloc - function that concatenates two strings
*@nmemb: amount of elements to be stored in array
*@size: size of each element stored in the array
*
*Return: pointer to the allocated memory
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array;
 unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
 }

 array = malloc(nmemb * size);
	if (!array)
	{
		return (NULL);
 }

 i = 0;
	while (i < nmemb * size)
	{
  array[i] = 0;
		i++;
 }

 return (array);
}
