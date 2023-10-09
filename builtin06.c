#include "shell.h"

/**
 * mylock_find - Locate an environment variable
 * @myenv: Array of environment variables
 * @mykey: Environment variable to locate
 *
 * Return: Pointer to the address of the environment variable
 */
char **mylock_find(char **myenv, char *mykey)
{
	unsigned int x, y, length;

	length = strlength(mykey);
	for (x = 0; myenv[x] != NULL; x++)
	{
		for (y = 0; y < length; y++)
			if (mykey[y] != myenv[x][y])
			{
				break;
			}
		if (y == length && myenv[x][y] == '=')
		{
			return (&myenv[x]);
		}
	}
	return (NULL);
}
