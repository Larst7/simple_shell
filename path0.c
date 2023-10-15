#include "shell.h"

/**
 * pathExe - Execute a command from the specified path.
 * @command: Complete path to the command.
 * @myvars: Pointer to struct of variables.
 *
 * Return: 0 on success, 1 on failure.
 */
int pathExe(char *command, vars_t *myvars)
{
	pid_t l_pid;

	if (access(command, X_OK) != 0)
	{
		errorPrint(myvars, ": Permission denied\n");
		myvars->status = 126;
		return (0);
	}

	l_pid = fork();
	if (l_pid == -1)
	{
		errorPrint(myvars, NULL);
		return (1);
	}
	if (l_pid == 0)
	{
		if (execve(command, myvars->av, myvars->env) == -1)
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
