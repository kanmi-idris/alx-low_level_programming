#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */

void print_all(const char *const format, ...)
{
int i = 0;
char *sep = "";

va_list print_all;
va_start(print_all, format);

while (format && format[i])
{
switch (format[i])
{
case 'c':
printf("%s%c", sep, va_arg(print_all, int));
break;
case 'i':
printf("%s%d", sep, va_arg(print_all, int));
break;
case 'f':
printf("%s%f", sep, va_arg(print_all, double));
break;
case 's':
{
char *str = va_arg(print_all, char *);
if (str == NULL)
str = "(nil)";
printf("%s%s", sep, str);
break;
}
default:
i++;
continue;
}
sep = ", ";
i++;
}
printf("\n");
va_end(print_all);
}
