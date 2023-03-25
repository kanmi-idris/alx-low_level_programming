#include "main.h"
#include <stdlib.h>

/**
*string_nconcat - function that concatenates two strings
*@s1: initial string to be concatenated
*@s2: second string to be concatenated
*@n: integer to limit amount of s2 to be concatenated
*
*Return: pointer to a newly allocated space in memory.
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int i, j, len_s2 = 0, str_len, len_s1 = 0;
char *memory;

if (s1 == NULL)
s1 = "";

if (s2 == NULL)
s2 = "";

for (i = 0; s1[i] != '\0'; i++)
len_s1++;

for (i = 0; s2[i] != '\0' && i < n; i++)
len_s2++;

if (n >= len_s2)
{
for (i = len_s2; s2[i]; i++)
len_s2++;
}

str_len = len_s1 + (n >= len_s2 ? len_s2 : n);
memory = malloc(sizeof(char) * (str_len + 1));
if (memory == NULL)
return (NULL);

for (i = 0; i < len_s1; i++)
memory[i] = s1[i];

for (j = 0; j < n; j++, i++)
memory[i] = s2[j];

memory[str_len] = '\0';

return (memory);
}
