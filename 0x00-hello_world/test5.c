#include <stdio.h>

/**
 * main - prints the phrase "Programming is like building a multilingual puzzle
 * Return: 0 if exited properly, non-zero otherwise
 */

void print(int nb)
{
    if (nb < 0) 
    {
        return;
    }
    printf("%d", nb);
    nb --;
    print(nb);
}

int main(void)
{
    print(4);
    return (0);
}
