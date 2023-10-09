#include "shell.h"

/**
 * key_add - Add a new environment variable
 * @myvars: Pointer to a struct of variables
 *
 * Return: void
 */

void key_add(vars_t *myvars)
{
	unsigned int y;
	char **n_environ;

	for (y = 0; myvars->env[y] != NULL; y++)
		;
	n_environ = malloc(sizeof(char *) * (y + 2));
	if (n_environ == NULL)
	{
		myerror_print(myvars, NULL);
		myvars->status = 127;
		exit(myvars);
	}
	for (y = 0; myvars->env[y] != NULL; y++)
	{
		n_environ[y] = myvars->env[y];
	}
	n_environ[y] = value_add(myvars->av[1], myvars->av[2]);
	if (n_environ[y] == NULL)
	{
		errorPrint(myvars, NULL);
		free(myvars->buffer);
		free(myvars->commands);
		free(myvars->av);
		environ_clear(myvars->env);
		free(n_environ);
		exit(127);
	}
	n_environ[y + 1] = NULL;
	free(myvars->env);
	myvars->env = n_environ;
}
