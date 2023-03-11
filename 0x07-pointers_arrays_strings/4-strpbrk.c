#include "main.h"
#include <stdio.h>

/**
 * *_strspn -  searches a string for any of a set of bytes.
 * @s: string to evaluate
 * @accept: string containing list of characters to match in s
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}
	return (NULL);
}
