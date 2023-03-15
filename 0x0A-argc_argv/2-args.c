#include "main.h"
#include <stdio.h>

/**
 * main -  prints  prints all arguments it receives..
 * @argc: number of arguments passed.
 * @argv: array of arguments passed.
 *
 * Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
int i;
for (i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}
return (0);
}
