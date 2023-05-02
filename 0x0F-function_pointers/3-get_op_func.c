#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function to perform the task
 * @s: operator to be passed as argument
 *
 * Return: index of first element which cmp does not return 0
 */

int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {{"+", op_add}, {"-", op_sub}, {"*", op_mul},
														{"/", op_div}, {"%", op_mod}, {NULL, NULL}};
int i = 0;

while (ops[i].op != NULL)
{
if (strcmp(s, ops[i].op) == 0)
{
return (ops[i].f);
}
i++;
}

return (NULL);
}
