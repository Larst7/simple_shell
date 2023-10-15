#include "shell.h"

/**
 * environ_create - Establish a shell environment based on the main argument.
 * @myenv: Environment provided to the main function.
 *
 * Description:
 * This function creates a new shell environment based on the environ
 * passed to the main function. It returns a pointer to the new environ.
 *
 * Return: Pointer to the updated environment
 */
char **environ_create(char **myenv)
{
	char **updated_env = NULL;
	size_t y;

	for (y = 0; myenv[y] != NULL; y++)
		;
	updated_env = malloc(sizeof(char *) * (y + 1));
	if (updated_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (y = 0; myenv[y] != NULL; y++)
	{
		updated_env[y] = dupstr(myenv[y]);
	}
	updated_env[y] = NULL;
	return (updated_env);
}
