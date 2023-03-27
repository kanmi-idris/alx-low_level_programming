#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_dog - initializes the variable of type struct dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the person who owns the dog
 * @d: structure variable to initialize the variable of type struct
 *
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
{
printf("Ok\n");
return (0);
}

d->name = name;
d->age = age;
d->owner = owner;
}
