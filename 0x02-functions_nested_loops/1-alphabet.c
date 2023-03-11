#include "main.h"

/**
 * print_alphabet-prints lowercase alphabets, followed by a new line.
 * Return: 0
 */
void print_alphabet(void)
{
char n = 'a';
while (n <= 'z')
{
_putchar(n);
n++;
}
_putchar('\n');
}
