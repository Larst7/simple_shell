#include "shell.h"
#include <string.h>

/**
 * pathFind - Find the PATH variable.
 * @myenv: Array of environment variables.
 *
 * Description:
 * This function searches for the PATH variable within the provided array
 * of environment variables. It returns a pointer to the node containing the
 * PATH variable, or NULL if not found.
 *
 * Return: Pointer to the node containing PATH, or NULL on failure.
 */
char *pathFind(char **myenv)
{
	char *path_variable = "PATH=";
	size_t path_len = strlen(path_variable);
	size_t l;

	if (myenv == NULL)
		return (NULL);

	while (*myenv)
	{
		char *env_var = *myenv;

		for (l = 0; env_var[l] != '\0' && l < path_len; l++)
		{
			if (env_var[l] != path_variable[l])
				break;
		}

		if (l == path_len)
		{
			return (env_var);
		}

		myenv++;
	}
	return (NULL);
}
