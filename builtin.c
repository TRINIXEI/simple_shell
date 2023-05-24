#include "shell.h"

/**
 * check_built - checks for builtin
 * @cmd: command entered
 * @argv: argument array
 *
 * Return: 0 or 1
 */

int check_built(char *cmd, char **carr)
{
	int i;
	built_in b_arr[] = {
		{"exit", exit_f},
		{NULL, NULL}};

	for (i = 0; b_arr[i].name != NULL; i++)
	{
		if (_strcmp(carr[0], b_arr[i].name) == 0)
			break;
	}
	if (b_arr[i].n != NULL)
	{
		b_arr[i].n(cmd, carr);
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

void exit_f(char *cmd, char **carr)
{
	if (carr[1] == NULL)
	{
		free(cmd);
		free_all(carr);
		exit(0);
	}
}
