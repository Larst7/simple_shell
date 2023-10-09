#include "shell.h"

/**
 * set_environ - Create a new environment variable or edit an existing one
 * @myvars: Pointer to a struct of variables
 *
 * Return: void
 */
void set_environ(vars_t *myvars)
{
	char **the_key;
	char *v;

	if (myvars->av[1] == NULL || myvars->av[2] == NULL)
	{
		errorPrint(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	/*Find the key*/
	the_key = mylock_find(myvars->env, myvars->av[1]);
	if (the_key == NULL)
	{
		key_add(myvars);
	}
	else
	{
		v = value_add(myvars->av[1], myvars->av[2]);
		if (v == NULL)
		{
			errorPrint(myvars, NULL);
			free(myvars->buffer);
			free(myvars->commands);
			free(myvars->av);
			environ_clear(myvars->env);
			exit(127);
		}
		/*Freeing the old value*/
		free(*the_key);
		*the_key = v;
	}
	/*Setting the exit status*/
	myvars->status = 0;
}
