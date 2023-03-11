#include "main.h"
#include <stdio.h>

/**
 * *_strspn - gets the length of a prefix substring.
 * @s: string to evaluate
 * @accept: string containing list of characters to match in s
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				break;
			}
		}
		if (!accept[j])
			{
				return count;
			}
	}
	return (count);
}
