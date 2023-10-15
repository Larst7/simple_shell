#include "shell.h"

/**
 * pathCheck - Verify is the command is present in the path
 * @myvars: Variables.
 *
 * Return: void.
 */
void pathCheck(vars_t *myvars)
{
	char *path;
	char **paths;
	int l;

	if (directory_check(myvars->av[0]))
	{
		cwdExe(myvars);
		return;
	}

	path = pathFind(myvars->env);
	if (path == NULL)
	{
		errorPrint(myvars, ": PATH environment variable is not set\n");
		myvars->status = 127;
		quit(myvars);
	}

	paths = my_token(path, ":");
	for (l = 0; paths && paths[l]; l++)
	{
		char *full_path = strcat(paths[l], myvars->av[0]);

		struct stat buff;

		if (stat(full_path, &buff) == 0)
		{
			pathExe(full_path, myvars);
			free(full_path);
			break;
		}
		free(full_path);
	}
	free(paths);
	if (paths[l] == NULL)
	{
		errorPrint(myvars, ": not found\n");
		myvars->status = 127;
		quit(myvars);
	}
}
