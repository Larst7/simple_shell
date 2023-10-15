#include "shell.h"

/**
 * set_environ - Establish a new environment variable or modify an existing one
 * @myvars: Pointer to a structure containing variables
 *
 * Return: Absence of a value
 */
void set_environ(vars_t *myvars)
{
	char **theKey;
	char *w;

	if (myvars->av[1] == NULL || myvars->av[2] == NULL)
	{
		errorPrint(myvars, ": Incorrect number of arguments\n");
		myvars->status = 2;
		return;
	}
	/*Locate the key*/
	theKey = mylock_find(myvars->env, myvars->av[1]);
	if (theKey == NULL)
	{
		key_add(myvars);
	}
	else
	{
		w = value_add(myvars->av[1], myvars->av[2]);
		if (w == NULL)
		{
			errorPrint(myvars, NULL);
			free(myvars->buffer);
			free(myvars->commands);
			free(myvars->av);
			environ_clear(myvars->env);
			exit(127);
		}
		/*Deallocating the old value*/
		free(*theKey);
		*theKey = w;
	}
	/*Assigning the exit status*/
	myvars->status = 0;
}
