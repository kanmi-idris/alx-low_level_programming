#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * @str: words to be splitted
 *
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
int i, j, len, num_words = 0;
char **words;
if (str == NULL || *str == '\0')
return (NULL);
for (i = 0; str[i]; i++)
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
num_words++;
}
if (num_words == 0)
return (NULL);
words = malloc(sizeof(char *) * (num_words + 1));
if (words == NULL)
return (NULL);
for (i = 0, j = 0; j < num_words; j++)
{
while (*str == ' ')
str++;
len = 0;
while (str[len] != ' ' && str[len] != '\0')
len++;
words[j] = malloc(sizeof(char) * (len + 1));
if (words[j] == NULL)
{
for (i = 0; i < j; i++)
free(words[i]); 
free(words);
return (NULL);
}
for (i = 0; i < len; i++)
words[j][i] = *(str++);
words[j][len] = '\0';
}
words[num_words] = NULL;
return (words);
}
