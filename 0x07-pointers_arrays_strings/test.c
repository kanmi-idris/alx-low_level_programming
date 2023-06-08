#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to pointer we need to set to
 * @to: string to set
 */
// void set_string(char **s, char *to)
// {
// 	*s = to;
// }

int main() {
    int *p;
    p = malloc(sizeof(int)); // allocate memory for p
    if (p == NULL) { // check if memory allocation was successful
        printf("Memory allocation failed\n");
        return 1;
    }
    *p = 42; // store a value in the memory location pointed to by p
    printf("value stored in the memory location pointed to by *p is %d\n", *p); // prints the value stored in the memory location pointed to by 
	printf("prints the size of *p %p\n", sizeof(unsigned int)); // prints the memory address stored in p
    printf("prints the memory address stored in p %p\n", p); // prints the memory address stored in p
    printf("prints the memory address of p %p\n", &p); // prints the memory address of p
    free(p); // release the memory allocated for p
    return 0;
}
