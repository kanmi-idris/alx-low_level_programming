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
if (strcmp(s, "+") == 0)
{
return (op_add);
}
else if (strcmp(s, "-") == 0)
{
return (op_sub);
}
else if (strcmp(s, "*") == 0)
{
return (op_mul);
}
else if (strcmp(s, "/") == 0)
{
return (op_div);
}
else if (strcmp(s, "%") == 0)
{
return (op_mod);
}

return (NULL);
}
