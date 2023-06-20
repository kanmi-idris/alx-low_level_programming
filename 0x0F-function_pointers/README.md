0x0F. C - Function pointers
This project is about learning how to use function pointers in C.

Description
In this project, I will write several C programs that demonstrate the concept and usage of function pointers. A function pointer is a variable that stores the address of a function that can be later called through that function pointer. This is useful for passing functions as arguments to other functions, returning functions from functions, and creating arrays of functions.

Files
The following files are part of this project:

0-print_name.c: A function that prints a name using a function pointer as an argument.
1-array_iterator.c: A function that executes a function given as a parameter on each element of an array using a function pointer as an argument.
2-int_index.c: A function that searches for an integer in an array using a function pointer as a comparison argument.
3-main.c: The main function for a program that performs simple mathematical operations. It uses function pointers to call the appropriate functions to perform the operations.
3-op_functions.c: A file containing the functions that perform the mathematical operations for the program in 3-main.c.
3-get_op_func.c: A function that selects the correct function to perform an operation based on a character argument. It returns a pointer to the function that corresponds to the operator given as a parameter.
3-calc.h: A header file containing all the function prototypes and data structures used by the program in 3-main.c.
function_pointers.h: A header file containing all the function prototypes for the functions in 0-print_name.c, 1-array_iterator.c, and 2-int_index.c.
_putchar.c: A C file containing the _putchar function that writes a character to standard output.
Requirements
All files are compiled on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89.
All files end with a new line.
Code follows the Betty style and document guidelines.
No global variables are allowed.
The only C standard library functions allowed are malloc, free, and exit. Any use of functions like printf, puts, calloc, realloc etc. is forbidden.
The prototypes of all functions and the data structure used by the program in 3-main.c are included in header file 3-calc.h.
The prototypes of all functions in 0-print_name.c, 1-array_iterator.c, and 2-int_index.c are included in header file function_pointers.h.
Learning Objectives
At the end of this project, I am expected to be able to explain to anyone, without the help of Google:

What are function pointers and how to use them
What does a function pointer exactly hold
Where does a function pointer point to in the virtual memory