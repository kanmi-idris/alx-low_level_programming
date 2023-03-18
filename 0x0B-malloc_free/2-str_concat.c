#include "main.h"
#include <stdlib.h>

/**
 * *str_concat() - returns a pointer to a space in memory.
 * @s1: string
 * @s2: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *str_concat(char *s1, char *s2)
{
char *store;
int i = 0, lenS1 = 0, lenS2 = 0, total_len;
if (s1 == NULL)
{
s1 = "";
}
if (s2 == NULL)
{
s2 = "";
}
while (s1[lenS1] != '\0')
{
lenS1++;
}
while (s2[lenS2] != '\0')
{
lenS2++;
}
total_len = lenS1 + lenS2;
store = malloc(sizeof(char) * (total_len + 1));
if (store == NULL)
{
return (NULL);
}
while (i < (lenS1))
{
store[i] = s1[i];
i++;
}
while (i < (lenS2))
{
store[i + lenS1] = s2[i];
i++;
}
store[total_len] = '\0';

return (store);
}
