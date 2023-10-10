#include "shell.h"

/**
 * my_token - Tokenizes a buffer using a specified delimiter.
 * @buff: Buffer to tokenize.
 * @mydlimiter: Delimiter used for tokenization.
 *
 * Return: Pointer to an array of pointers to the token.
 */
char **my_token(char *buff, char *mydlimiter)
{
	char **token = NULL;
	size_t y = 0;
	size_t m_count = 10;

	if (buff == NULL)
	{
		return (NULL);
	}

	token = malloc(sizeof(char *) * m_count);
	if (token == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	for (; y < m_count; y++)
	{
		token[y] = strtoken(buff, mydlimiter);
		if (token[y] == NULL)
			break;
		if (y == m_count - 1)
		{
			token = rellocat(token, &m_count);
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
