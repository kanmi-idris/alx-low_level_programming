#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @n: no of integers to be passed
 * @separator: string to be printed between numbers
 *
 * Return: 0 (successful)
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
unsigned int i = 0;
va_list(print_str);
va_start(print_str, n);

while (i < n)
{

char *str = va_arg(print_str, char *);
if (str == NULL)
{
printf("(nil)");
}
else
{
printf("%s", str);
if (i < n - 1 && separator != NULL)
printf("%s", separator);
}

i++;
}
printf("\n");
va_end(print_str);
}
