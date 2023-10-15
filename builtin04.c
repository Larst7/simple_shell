#include "shell.h"

/**
 * unset_environ - Delete an environment variable
 * @myvars: Pointer to a structure containing variables
 *
 * Return: void
 */
void unset_environ(vars_t *myvars)
{
	char **key, **new_env;

	unsigned int x, y;

	if (myvars->av[1] == NULL)
	{
		errorPrint(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	key = mylock_find(myvars->env, myvars->av[1]);
	if (key == NULL)
	{
		errorPrint(myvars, ": No variable to unset");
		return;
	}
	for (x = 0; myvars->env[x] != NULL; x++)
		;
	new_env = malloc(sizeof(char *) * x);
	if (new_env == NULL)
	{
		errorPrint(myvars, NULL);
		myvars->status = 127;
		quit(myvars);
	}
	for (x = 0; myvars->env[x] != *key; x++)
	{
		new_env[x] = myvars->env[x];
	}
	for (y = x + 1; myvars->env[y] != NULL; y++, x++)
		new_env[x] = myvars->env[y];
	new_env[x] = NULL;
	free(*key);
	free(myvars->env);
	myvars->env = new_env;
	myvars->status = 0;
}
