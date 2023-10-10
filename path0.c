#include "shell.h"

/**
 * pathExe - Execute a command from the specified path.
 * @mycommand: Full path to the command.
 * @myvars: Pointer to struct of variables.
 *
 * Return: 0 on success, 1 on failure.
 */
int pathExe(char *mycommand, vars_t *myvars)
{
	pid_t c_pid;

	if (access(mycommand, X_OK) != 0)
	{
		errorPrint(myvars, ": Permission denied\n");
		myvars->status = 126;
		return (0);
	}

	c_pid = fork();
	if (c_pid == -1)
	{
		errorPrint(myvars, NULL);
		return (1);
	}
	if (c_pid == 0)
	{
		if (execve(mycommand, myvars->av, myvars->env) == -1)
		{
			errorPrint(myvars, NULL);
			_exit(1);
		}
	}
	else
	{
		wait(&myvars->status);
		if (WIFEXITED(myvars->status))
		{

			myvars->status = WEXITSTATUS(myvars->status);
		}
		else if (WIFSIGNALED(myvars->status) && WTERMSIG(myvars->status) == SIGINT)
		{
			myvars->status = 130;
		}

		return (0);
	}
	myvars->status = 127;
	return (1);
}
