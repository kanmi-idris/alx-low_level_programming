#ifndef DOG_H
#define DOG_H

/**
 * struct dog - contains details of a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the person who owns the dog
 *
 * Description: this structure is a storage for the details of dogs.
 */
typedef struct dog
{
char *name;
float age;
char *owner;
} dog_t;

int _putchar(char c);
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif
