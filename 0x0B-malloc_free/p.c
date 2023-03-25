#include <stdio.h>
#include <stdlib.h>

char *create_array(unsigned int size, char c)
{
    char *ptArray;

    ptArray = malloc(size * sizeof(char));

    printf("%p", ptArray);

    return (ptArray);
}

int main(void)
{
    char *buffer;

    buffer = create_array(1, 'A');
    if  (buffer == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    free(buffer);
    return (0);
}