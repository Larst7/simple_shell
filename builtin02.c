#include "shell.h"

/**
 * my_env - Display the current environment variables.
 * @myvars: A struct holding environment-related information.
 *
 * Description:
 * This function outputs the current environment vars to the stndout.
 *
 * Return: void
 */

void my_env(vars_t *myvars)
{
	/* Set up a counter for iterating through the environment */
	unsigned int y = 0;

	/* Continue looping until reaching the end of the environment array */
	while (myvars->env[y])
	{
		/* Output the current environment variable */
		my_puts(myvars->env[y]);

		/* Output a newline character to separate variables */
		my_puts("\n");
		y++;
	}
	/* Set the status to indicate successful operation */
	myvars->status = 0;
}
