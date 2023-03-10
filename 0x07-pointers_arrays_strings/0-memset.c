#include "main.h"
#include <stddef.h>

/**
 * _memset() - fills the memory with a constant byte
 * @n: number of bytes to be filled into the memory
 * @b: constant to fill the memory with
 * @s: pointer to the memory which will be filled
 *
 *  Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    if (s != NULL)
    { /*Prevents segmentation fault when s is null*/

        if (n != 0)
        { /*Prevents undefined results when n is 0*/

            if (b >= -128 && b <= 127)
            { /*Prevents b from not being a valid character*/

                for (unsigned int i = 0; i < n; i++)
                {
                    s[i] = b;
                }

                s[n] = '\0'; // add null character at the end
            }
        }
    }

    return (s);
}
