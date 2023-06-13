#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
int i, j, k, len = 0;
char *concat;

if (ac == 0 || av == NULL)
{
return (NULL);
}

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
len++;
len++;
}

concat = malloc(sizeof(char) * (len + 1));
if (concat == NULL)
{
return (NULL);
}

k = 0;
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
{
concat[k] = av[i][j];
k++;
}
concat[k] = '\n';
k++;
}
concat[k] = '\0';

return (concat);
}
