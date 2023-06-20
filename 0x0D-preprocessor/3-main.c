#include "3-function_like_macro.h"
#include <stdio.h>

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
#ifndef ABS
printf("The macro 'ABS' is not defined\n");
return (1);
#else
printf("%d\n", ABS(1024 - 2048));
return (0);
#endif
}
