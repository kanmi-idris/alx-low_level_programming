#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers.
 * @argc: number of arguments passed.
 * @argv: array of arguments passed.
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    int result;
    if (argc <= 2)
    {
        printf("Error\n");
        return (1);
    }
    else
    {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        result = x * y;
        printf("%d\n", result);
    }

    return (0);
}
