#include "main.h"
#include <stdio.h>
/**
* _strlen_recursion - returns the factorial of a given number.
* @n: integer number
* Return: factorial of a given number.
*/
int factorial(int n)
{
if (n < 0)
{
return (-1);
}
if (n == 0)
{
return (1);
}
return (_strlen_recursion(n * (n - 1)));
}

int main(void)
{
    int r;

    r = factorial(1);
    printf("%d\n", r);
    r = factorial(5);
    printf("%d\n", r);
    r = factorial(10);
    printf("%d\n", r);
    r = factorial(-1024);
    printf("%d\n", r);
    return (0);
}