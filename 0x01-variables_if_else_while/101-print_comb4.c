#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i, j, k;

    for (i = 0; i < 1000; i++)
    {
        j = i / 10; /* Get the tens digit */
        k = i % 10; /* Get the ones digit */

        if (j < k) /* Make sure digits are in ascending order */
        {
            j = j % 10; /* Remove the tens digit from j */
            putchar((i / 100) + '0'); /* Print the hundreds digit */
            putchar(j + '0'); /* Print the tens digit */
            putchar(k + '0'); /* Print the ones digit */

            if (i != 789) /* Don't print comma and space after last number */
            {
                putchar(',');
                putchar(' ');
            }
        }
    }

    putchar('\n'); /* Print a newline at the end */
    return (0);
}
