#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked -  allocates memory using malloc
 * @b: integer argument
 * 
 * Return - Pointer to allocated memory
*/

void *malloc_checked(unsigned int b)
{
    void *memory;
    memory = malloc(sizeof(unsigned int) * b);
    if (memory == NULL)
    {
        exit(98);
    }

    return (memory);
}