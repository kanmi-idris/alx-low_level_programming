#include "main.h"
#include <stdlib.h>

/**
 * _strdup()- returns a pointer to a space in memory.
 * @str: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
char *nstr;
int i = 0, len = 0;
if (str == NULL)
{
return (NULL);
}
while (str[len] != '\0')
{
len++;
}
nstr = malloc(sizeof(char) * len);
if (nstr == NULL)
{
return (NULL);
}
while (i < len)
{
nstr[i] = str[i];
i++;
}

return (nstr);
}
