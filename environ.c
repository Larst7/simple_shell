#include "shell.h"

/**
 * environ_create - Create shell environment from main argument.
 * @myenv: Environment passed to main.
 *
 * Description:
 * This function creates a new shell environment based on the environ
 * passed to the main function. It returns a pointer to the new environ.
 *
 * Return: Pointer to the new environment.
 */
char **environ_create(char **myenv)
{
	char **new_environ = NULL;
	size_t y;

	for (y = 0; myenv[y] != NULL; y++)
		;
	new_environ = malloc(sizeof(char *) * (y + 1));
	if (new_environ == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (y = 0; myenv[y] != NULL; y++)
	{
		new_environ[y] = dupstr(myenv[y]);
	}
	new_environ[y] = NULL;
	return (new_environ);
}
