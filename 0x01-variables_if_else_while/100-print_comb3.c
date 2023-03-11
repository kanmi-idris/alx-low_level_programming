#include <stdlib.h>
#include <stdio.h>
/*
 * main -  print all possible different combinations of two digits
 *
 * Description: using the main function
 * this program prints "all possible different combinations of two digits"
 * Return: 0
 */

int main(void)
{
    int i = 0;
    int j = 0;

    while (i < 100)
    {
        j = i + 1;

        while (j < 100)
        {

            if ((i / 10 != i % 10) && (j / 10 != j % 10) && (i < j))
            {
                if ((i != 0) || (j != 0))
                {
                    printf("%d%d, ", i / 10, i % 10);
                    printf("%d%d", j / 10, j % 10);

                    if ((i != 98) || (j != 99))
                    {
                        putchar(',');
                        putchar(' ');
                    }
                }
            }

            j++;
        }

        i++;
    }

    return (0);
}