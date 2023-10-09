#include "shell.h"

/**
 * checkbins - This program checks if the command is a builtin
 * @myvars: variables
 *
 * Return: pointer to the function or NULL
 */
void (*checkbins(vars_t *myvars))(vars_t *myvars)
{
	my_bins check[] = {
		{"exit", exit},
		{"env", my_env},
		{"setenv", set_environ},
		{"unsetenv", unset_environ},
		{NULL, NULL}
	};

	unsigned int x = 0;

	while (check[x].name != NULL)
	{
		if (cmprstr(myvars->av[0], check[x].name) == 0)
		{
			check[x].f(myvars);
			return (check[x].f);
		}
		x++;
	}

	return (NULL);
}
