#include "shell.h"

/**
 * puts4 - Print a string to standard error.
 * @mystr: String to print.
 */
void puts4(char *mystr)
{
	ssize_t length;

	char *current = mystr;

	while (*current)
	{
		length = write(STDERR_FILENO, current, 1);

		if (length != 1)
		{
			perror("Fatal Error");
			exit(1);
		}

		current++;
	}
}
