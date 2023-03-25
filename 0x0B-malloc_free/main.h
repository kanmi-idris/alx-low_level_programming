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
char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);
char *argstostr(int ac, char **av);
char **strtow(char *str); 

#endif