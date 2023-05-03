#Variadic Functions
This project contains two tasks that demonstrate the use of variadic functions in C.

##Task 0: Beauty is variable, ugliness is constant
This task requires you to write a function that returns the sum of all its parameters. The prototype for this function is int sum_them_all(const unsigned int n, ...);. If n == 0, the function should return 0.

The code for this task can be found in the file 0-sum_them_all.c in the 0x10-variadic_functions directory of the alx-low_level_programming GitHub repository.

##Task 1: To be is to be the value of a variable
This task requires you to write a function that prints numbers, followed by a new line. The prototype for this function is void print_numbers(const char *separator, const unsigned int n, ...);. The separator parameter is the string to be printed between numbers and n is the number of integers passed to the function. You are allowed to use printf. If separator is NULL, it should not be printed. A new line should be printed at the end of your function.

The code for this task can be found in the file 1-print_numbers.c in the 0x10-variadic_functions directory of the alx-low_level_programming GitHub repository.