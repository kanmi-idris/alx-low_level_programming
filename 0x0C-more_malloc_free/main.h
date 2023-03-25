#ifndef FILE_MAIN
#define FILE_MAIN

/**
 * #ifndef FILE_MAIN - This line checks whether the macro FILE_MAIN has already been defined. If it hasn't been defined, the code between #ifndef and
 * #endif will be included in the program. If it has already been defined, the code will be skipped.
 * #define FILE_MAIN - This line defines the macro FILE_MAIN. If it hasn't already been defined, this line will define it. If it has already been defined
 * this line will have no effect.
 * #endif - This line marks the end of the code block that is conditionally included based on whether FILE_MAIN has been defined.
 * 
 * Putting these three lines of code together creates a "header guard" that helps prevent multiple inclusions of the same header file
*/
int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif