#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new;
list_t *last = *head;
size_t len = 0;

while (str[len])
len++;

new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);

new->str = strdup(str);
new->len = len;
new->next = NULL;

if (*head == NULL)
{
*head = new;
return (new);
}

while (last->next != NULL)
last = last->next;

last->next = new;

return (new);
}
