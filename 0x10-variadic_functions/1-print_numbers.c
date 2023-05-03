#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line.
 * @n: no of integers to be passed
 * @separator: string to be printed between numbers
 *
 * Return: 0 (successful)
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i = 0;
va_list(print_nums);
va_start(print_nums, n);

while (i < n)
{
printf("%d", va_arg(print_nums, int));
if (i < n-1 && separator != NULL)
printf("%s", separator);

i++;
}
printf("\n");
va_end(print_nums);
}
