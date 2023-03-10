#include "main.h"

/**
 * _memset() - fills the memory with a constant byte
 * @n: number of bytes to be filled into the memory
 * @b: constant to fill the memory with
 * @s: pointer to the memory which will be filled
 *
 *  Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
