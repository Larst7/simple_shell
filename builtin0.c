#include "shell.h"

/**
 * checkbins - This program verifies whether the command is an inherent function.
 * @myvars: variables
 *
 * Return: pointer to the function or NULL
 */
void (*checkbins(vars_t *myvars))(vars_t *myvars)
{
	my_bins check[] = {
		{"exit", quit},
		{"env", my_env},
		{"setenv", set_environ},
		{"unsetenv", unset_environ},
		{NULL, NULL}
	};

	unsigned int y = 0;

	while (check[y].name != NULL)
	{
		if (cmprstr(myvars->av[0], check[y].name) == 0)
		{
			check[y].f(myvars);
			return (check[y].f);
		}
		y++;
	}

	return (NULL);
}
