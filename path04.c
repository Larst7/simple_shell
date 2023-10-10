#include "shell.h"

/**
 * directory_check - checks if the command is a part of a path
 * @mystr: command
 *
 * Return: 1 on success, 0 on failure
 */
int directory_check(char *mystr)
{
	unsigned int y;

	for (y = 0; mystr[y]; y++)
	{
		if (mystr[y] == '/')
		{
			return (1);
		}
	}
	return (0);
}
