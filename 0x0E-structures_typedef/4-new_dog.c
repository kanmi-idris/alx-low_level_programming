#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - function that creates a new dog.
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the person who owns the dog
 *
 * Return: new_dog details
 */

dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
char *new_name;
char *new_owner;

if (!name || !owner || !age)
return (NULL);

new_dog = malloc(sizeof(dog_t));
if (!new_dog)
return (NULL);

new_name = malloc(strlen(name) + 1);
if (!new_name)
{
free(new_dog);
return (NULL);
}

new_owner = malloc(strlen(owner) + 1);
if (!new_owner)
{
free(new_dog);
free(new_name);
return (NULL);
}

strcpy(new_owner, owner);


new_dog->age = age;
new_dog->name = new_name;
new_dog->owner = new_owner;

return (new_dog);
}
