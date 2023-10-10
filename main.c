#include "shell.h"

/**
 * signal_handler - Handles the ^C signal interrupt.
 * @uuv: Unused variable (required by the signal function prototype).
 *
 * Return: void.
 */
static void signal_handler(int uuv)
{
	unsigned int sig_flag = 0;
	(void) uuv;

	if (sig_flag == 0)
	{
		my_puts("\n$ ");
	}
	else
	{
		my_puts("\n");
	}
}

/**
 * main - Main function for the shell.
 * @argc: Number of arguments passed to main.
 * @argv: Array of arguments passed to main.
 * @environment: Array of environment variables.
 *
 * Return: 0 for successful execution, exit status on failure, or ? for undetermined.
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t length_buffer = 0;
	unsigned int itspipe = 0, y;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;

	vars.env = environ_create(environment);
	signal(SIGINT, signal_handler);
	if (!isatty(STDIN_FILENO))
		itspipe = 1;
	if (itspipe == 0)
		my_puts("$ ");
	while (getline(&(vars.buffer), &length_buffer, stdin) != -1)
	{
		vars.count++;
		vars.commands = my_token(vars.buffer, ";");
		for (y = 0; vars.commands && vars.commands[y] != NULL; y++)
		{
			vars.av = my_token(vars.commands[y], "\n \t\r");
			if (vars.av && vars.av[0])
				if (checkbins(&vars) == NULL)
				{
					pathCheck(&vars);
				}
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		if (itspipe == 0)
			my_puts("$ ");
		vars.buffer = NULL;
	}
	if (itspipe == 0)
	{
		my_puts("\n");
	}
	environ_clear(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
