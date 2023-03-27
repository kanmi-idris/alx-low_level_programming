#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - function that prints a struct dog
 * @d: structure variable to initialize the variable of type struct
 *
 * Return: void
 */

void print_dog(struct dog *d)
{
if (d->name == NULL)
{
printf("Name: (nil)");
}
else if (d->owner == NULL)
{
printf("Owner: (nil)");
}
else if (!d->age)
{
printf("Age: (nil)");
}

printf("Name: %s\n", d->name);
printf("Age: %f\n", d->age);
printf("Owner: %s\n", d->owner);

if (d == NULL)
{
printf("\n");
}
}
