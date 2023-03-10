#include "main.h"
#include <stdio.h>

/**
 * _strchr - locates a character in a string.
 * @s: pointer to string.
 * @c: character to search for.
 *
 * Return: pointer to the first occurrence of character c in string s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
        int i;

        for (i = 0; i <= strlen(s); i++)
        {
                if (c == s[i])
                {
					return (&s[i]);
				}
        }
        return (NULL);
}
