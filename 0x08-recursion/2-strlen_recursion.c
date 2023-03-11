#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - prints a string in reverse.
 * @s: string to be printed
 */
int _strlen_recursion(char *s)
{
    if (*s == '\0')
	{
		return (0);
	}

    return (1 + _strlen_recursion(s + 1));
}
