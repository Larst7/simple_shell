#include "shell.h"

/**
 * environ_clear - Free the shell's environment.
 * @myenv: Shell's environment.
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
