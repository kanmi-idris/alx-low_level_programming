#include "main.h"
#include <stdlib.h>

/**
 *_realloc - reallocates a memory block with malloc & free
 *@ptr:  pointer to the memory allocated with a call to malloc(old_size)
 *@old_size: size in bytes of the allocated space for ptr
 *@new_size: in bytes of the new memory block
 *
 *Return: pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *memory;
char *old_ptr = ptr;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

memory = malloc(new_size);
if (memory == NULL)
return (NULL);

for (i = 0; i < old_size && i < new_size; i++)
memory[i] = old_ptr[i];

free(ptr);

return (memory);
}
