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
	char *new_env;

	length1 = strlength(mykey);
	length2 = strlength(myvalue);
	new_env = malloc(sizeof(char) * (length1 + length2 + 2));
	if (new_env == NULL)
	{
		return (NULL);
	}
	for (a = 0; mykey[a] != '\0'; a++)
	{
		new_env[a] = mykey[a];
	}
	new_env[a] = '=';
	for (b = 0; myvalue[b] != '\0'; b++)
	{
		new_env[a + 1 + b] = myvalue[b];
	}
	new_env[a + 1 + b] = '\0';
	return (new_env);
}
