#include "shell.h"
#include <string.h>

/**
 * pathFind - Locate the Path variable
 * @myenv: Array containing environment variables.
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
	char *path_var = "PATH=";
	size_t path_length = strlength(path_var);
	size_t l;

	if (myenv == NULL)
		return (NULL);

	while (*myenv)
	{
		char *env_var = *myenv;

		for (l = 0; env_var[l] != '\0' && l < path_length; l++)
		{
			if (env_var[l] != path_var[l])
				break;
		}

		if (l == path_length)
		{
			return (env_var);
		}

		myenv++;
	}
	return (NULL);
}
