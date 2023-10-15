#include "shell.h"

/**
 * environ_clear - Release the allocated memory for the shell's environment.
 * @myenv: Shell environment.
 *
 * Description:
 * This function deallocates the memory used by the shell's environment.
 *
 * Return: void
 */

void environ_clear(char **myenv)
{
	unsigned int y;

	for (y = 0; myenv[y] != NULL; y++)
	{
		free(myenv[y]);
	}
	free(myenv);
}
