#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers.
 * @argc: number of arguments passed.
 * @argv: array of arguments passed.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
int result = 0;
int i, j;

if (argc == 1)
{
printf("0\n");
return (1);
}
for (i = 1; i < argc; i++)
{
j = atoi(argv[i]);
if (j == 0 && *argv[i] != '0')
{
printf("Error\n");
return (1);
}

if (j < 0)
{
printf("Error\n");
return (1);
}
result += j;
}

printf("%d\n", result);

return (0);
}
