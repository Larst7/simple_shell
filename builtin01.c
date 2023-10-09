#include "shell.h"

/**
 * exit - Function to exit the program with a specified status code
 * @myvars: Variables containing command and status
 *
 * Return: void
 */

void exit(vars_t *myvars)
{
	int exit_status;

		while (cmprstr(myvars->av[0], "exit") == 0 && myvars->av[1] != NULL)
	{
		exit_status = my_latoi(myvars->av[1]);

		if (exit_status == -1)
		{
			myvars->status = 2;
			errorPrint(myvars, ": Illegal number: ");
			puts4(myvars->av[1]);
			puts4("\n");
			free(myvars->commands);
			myvars->commands = NULL;
			return;
		}

		myvars->status = exit_status;
		break;
	}

	free(myvars->buffer);
	free(myvars->av);
	free(myvars->commands);
	environ_clear(myvars->env);
	exit(myvars->status);
}
