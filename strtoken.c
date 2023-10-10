#include "shell.h"
/**
 * checkMatch - Check if a character matches any in a string.
 * @c: Character to check.
 * @str: String to check.
 *
 * Description:
 * This function checks if a character matches any character in a given string.
 * It returns 1 if there is a match, and 0 if there isn't.
 *
 * Return: 1 if there is a match, 0 if not.
 */
unsigned int checkMatch(char c, const char *str)
{
	unsigned int y;

	for (y = 0; str[y] != '\0'; y++)
	{
		if (c == str[y])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * strtoken - Custom string token.
 * @mystr: String to tokenize.
 * @mydelim: Delimiter to tokenize against.
 *
 * Description:
 * This function provides a custom implementation of the strtok function.
 * It tokenizes the input string based on the provided delimiter and returns
 * a pointer to the next token or NULL if there are no more tokens.
 *
 * Return: Pointer to the next token or NULL.
 */
char *strtoken(char *mystr, const char *mydelim)
{
	static char *start_token;
	static char *token_next;
	unsigned int y;

	if (mystr != NULL)
		token_next = mystr;
	start_token = token_next;
	if (start_token == NULL)
		return (NULL);
	for (y = 0; token_next[y] != '\0'; y++)
	{
		if (checkMatch(token_next[y], mydelim) == 0)
		{
			break;
		}
	}

	start_token = token_next + y;
	token_next = start_token;
	for (y = 0; token_next[y] != '\0'; y++)
	{
		if (checkMatch(token_next[y], mydelim) == 1)
			break;
	}
	if (token_next[y] == '\0')
	{
		token_next = NULL;
	}
	else
	{
		token_next[y] = '\0';
		token_next = token_next + y + 1;
		if (*token_next == '\0')
			token_next = NULL;
	}
	return (start_token);
}
