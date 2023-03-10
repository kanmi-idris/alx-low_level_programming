#include "main.h"
#include <stdio.h>

/**
 * *_strchr -  locates a character in a string.
 * @s: string
 * @c: character to be looked for in the string
 *
 * Return: pointer to the first occurrence of the c in the s, or NULL if the c is not found
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; i <= strlen(s); i++)
	{
		if(c == s[i])
		{
			return &s[i];
		}
	}

	return NULL;
}
