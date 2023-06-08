#include <stdlib.h>
#include <stdio.h>

/**
 *main - multiplies two positive numbers
 *@argc: no of arguments passed
 *@argv: array of arguments passed
 *
 *Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
int num1, num2, result;
int i;

if (argc != 3)
{
printf("Error\n");
exit(98);
}

for (i = 1; i < argc; i++)
{
char *arg = argv[i];
while (*arg)
{
if (*arg < '0' || *arg > '9')
{
printf("Error\n");
exit(98);
}
arg++;
}
}

num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
result = num1 *num2;
printf("%d\n", result);

return (0);
}
