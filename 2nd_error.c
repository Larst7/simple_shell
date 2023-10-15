#include "shell.h"

/**
 * uitoa - Convert an unsigned int to a string.
 * @mycount: Unsigned int to convert.
 *
 * Description:
 * This function converts the provided unsigned integer into a string.
 * It returns a pointer to the converted string.
 *
 * Return: Pointer to the converted string.
 */

char *uitoa(unsigned int mycount)
{
	char *numstring;
	int start = 0, end;

	if (mycount == 0)
	{
		numstring = malloc(sizeof(char) * 2);
		if (numstring == NULL)
		{
			perror("Fatal Error1");
			exit(127);
		}
		numstring[0] = '0';
		numstring[1] = '\0';
		return (numstring);
	}

	numstring = uitoa(mycount / 10);
	end = strlen(numstring) - 1;
	numstring = realloc(numstring, sizeof(char) * (strlen(numstring) + 2));
	if (numstring == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}

	/* Reverse the string */
	while (start < end)
	{
		char temp = numstring[start];

		numstring[start] = numstring[end];

		numstring[end] = temp;
		start++;
		end--;
	}

	return (numstring);
}

/**
 * errorPrint - This Prints error messages to standard error.
 * @myvars: Pointer to structure of variables.
 * @mymsg: Message to print out.
 *
 * Return: void
 */

void errorPrint(vars_t *myvars, char *mymsg)
{
	char *count = uitoa(myvars->count);

	if (!count)
	{
		perror("uitoa failed");
		exit(EXIT_FAILURE);
	}

	puts4(myvars->argv[0]);
	puts4(": ");
	puts4(count);
	puts4(": ");
	puts4(myvars->av[0]);

	if (mymsg)
	{
		puts4(mymsg);
	}
	else
	{
		perror("");
	}

	free(count);
}
