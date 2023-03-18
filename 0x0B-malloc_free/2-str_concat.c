#include "main.h"
#include <stdlib.h>

/**
 * _*str_concat()- returns a pointer to a space in memory.
 * @s1: string
 * @s2: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *str_concat(char *s1, char *s2)
{
    char *store;
    int i = 0, j = 0, total_len;
    if (s1 == NULL)
    {
        s1 = "";
    }
    if (s2 == NULL)
    {
        s2 = "";
    }
    while (s1[i] || s2[i])
    {
        i++;
    }
    total_len = i;
    store = malloc(sizeof(char) * (total_len + 1));
    if (store == NULL)
    {
        return (NULL);
    }
    while (s1[i])
    {
        store[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        store[i] = s2[j];
        i++;
        j++;
    }
    store[total_len] = '\0';

    return (store);
}
