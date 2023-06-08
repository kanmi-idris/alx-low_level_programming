#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sums all its arguments together
 * @n: argument to determine the length of the arguments to be added
 *
 * Return: sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
unsigned int i = 0, sum = 0;
va_list(nums);
va_start(nums, n);

if (n == 0)
{
return (0);
}

while (i < n)
{
sum = sum + va_arg(nums, int);
i++;
}
return (sum);
}
