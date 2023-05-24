#include "shell.h"

/**
 * check_built - checks for builtin
 * @cmd: command entered
 * @argv: argument array
 *
 * Return: 0 or 1
 */

int check_built(char *cmd, char **argv)
{
	int i;
	built_in b_arr[] = {
		{"exit", exit_f},
		{NULL, NULL}};

	for (i = 0; b_arr[i].name != NULL; i++)
	{
		if (_strcmp(cmd, b_arr[i].name) == 0)
			break;
	}
	if (b_arr[i].n != NULL)
	{
		b_arr[i].n(cmd, argv);
		return (0);
	}
	return (1);
}

/**
 * exit_f - exit from shell
 * @cmd: command entered
 * @argv: arguments array
 *
 * Return: 1 or 0
 */

void exit_f(char *cmd, char **argv)
{
	if (argv[1] == NULL)
	{
		free(cmd);
		free_all(argv);
		exit(0);
	}
}
