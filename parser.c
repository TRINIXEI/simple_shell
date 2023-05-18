#include "shell.h"

/**
 * processor - evaluates the command entered
 * @argv: the argument array of commands
 *
 * Return: int
 */

int  processor(char **argv)
{
	pid_t child;
	struct stat statbuff;
	int status;

	if(stat(argv[0], &statbuff) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror("/hsh");
			return (1);
		}
		else if (child == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror("/hsh");
		}
		else
		{
			wait(&status);
		}
		return (0);
	}
	else
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("/hsh");
		return (0);
	}
}

/**
 * sig_handler -  handles signal
 * @sig_int - value for SIGINT
 *
 * Return: void
 */

void sig_handler(int sig_int)
{
	if (sig_int == SIGINT)
		_putchar('\n');
}
