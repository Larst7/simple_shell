#include "shell.h"

/**
 * value_add - Create a new environment variable with a specified key & value.
 * @mykey: Pointer to the key string.
 * @myvalue: Pointer to the value string.
 *
 * Description:
 * This function combines the provided key and value strs to form a new environ
 * variable. Dynamic memory allocation is used for the new variable.
 *
 * Return:
 * Pointer to the newly created environ variables
 */
char *value_add(char *mykey, char *myvalue)
{
	unsigned int length1, length2, a, b;
	char *n_environ;

	length1 = strlength(mykey);
	length2 = strlength(myvalue);
	n_environ = malloc(sizeof(char) * (length1 + length2 + 2));
	if (n_environ == NULL)
	{
		return (NULL);
	}
	for (a = 0; mykey[a] != '\0'; a++)
	{
		n_environ[a] = mykey[a];
	}
	n_environ[a] = '=';
	for (b = 0; myvalue[b] != '\0'; b++)
	{
		n_environ[a + 1 + b] = myvalue[b];
	}
	n_environ[a + 1 + b] = '\0';
	return (n_environ);
}
