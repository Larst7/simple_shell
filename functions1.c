#include "shell.h"

/**
 * dupstr - Create a copy of a string.
 * @mystrtodup: The original string to duplicate.
 *
 * Return: A pointer to the newly duplicated string.
 */
char *dupstr(char *mystrtodup)
{
	size_t length;
	char *the_copy;
	size_t l;

	if (mystrtodup == NULL)
	{
		return (NULL);
	}

	length = strlen(mystrtodup);
	the_copy = malloc((length + 1) * sizeof(char));
	if (the_copy == NULL)
	{
		return (NULL);
	}

	for (l = 0; l <= length; l++)
	{
		the_copy[l] = mystrtodup[l];
	}

	return (the_copy);
}

/**
 * str_cat - Concatenates two strings.
 * @mystrc1: The first string.
 * @mystrc2: The second string.
 *
 * Return: A pointer.
 */


char *str_cat(char *mystrc1, char *mystrc2)
{
	size_t length1;
	size_t length2;
	size_t n_length;
	size_t y;
	size_t l;

	char *new_str;

	if (mystrc1 == NULL || mystrc2 == NULL)
	{
		return (NULL);
	}

	length1 = strlen(mystrc1);
	length2 = strlen(mystrc2);
	n_length = length1 + length2 + 2;

	new_str = malloc(n_length * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}

	for (l = 0; l < length1; l++)
	{
		new_str[l] = mystrc1[l];
	}
	new_str[length1] = '/';

	for (y = 0; y < length2; y++)
	{
		new_str[length1 + 1 + y] = mystrc2[y];
	}

	new_str[n_length - 1] = '\0';

	return (new_str);
}

/**
 * my_puts - Outputs a string to standard output.
 * @strng: String to be displayed.
 *
 * Return: Number of characters printed, or -1 in case of failure.
 */
ssize_t my_puts(char *strng)
{
	ssize_t number = strlength(strng);
	ssize_t length = write(STDOUT_FILENO, strng, number);

	if (length != number)
	{
		perror("Fatal Error");
		return (-1);
	}

	return (length);
}