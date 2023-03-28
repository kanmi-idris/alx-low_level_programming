#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory for the dog created
 * @d: structure variable to be passed as an argument
 *
 * Return: void
 */

void free_dog(dog_t *d)
{
if (d != NULL)
{
free(d->name);
free(d->owner);
free(d);
}
}
