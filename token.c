#include "shell.h"

/**
 * my_token - This function breaks down a buffer using a designated delimiter.
 * @buff: Character sequence for token extraction.
 * @dlimiter: Character used to separate tokens
 *
 * Return:  Pointer to an array of pointers, each pointing to a token.
 */
char **my_token(char *buff, char *dlimiter)
{
	char **token = NULL;
	size_t y = 0;
	size_t l_count = 10;

	if (buff == NULL)
	{
		return (NULL);
	}

	token = malloc(sizeof(char *) * l_count);
	if (token == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	for (; y < l_count; y++)
	{
		token[y] = strtoken(buff, dlimiter);
		if (token[y] == NULL)
			break;
		if (y == l_count - 1)
		{
			token = rellocat(token, &l_count);
			if (token == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}

	return (token);
}
