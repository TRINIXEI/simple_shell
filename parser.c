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

	if (stat(argv[0], &statbuff) == 0)
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
 * @sig_int: value for SIGINT
 *
 * Return: void
 */

void sig_handler(int sig_int)
{
	if (sig_int == SIGINT)
		_putchar('\n');
}

/**
 * build_path - build path of executable command
 * @argv: argument variable
 *
 * Return: full path
 */

char *build_path(char **argv)
{
	struct stat buffer;
	char *path, *full_path;
	char **path_arr;
	int i = 0, len, path_len;

	path = _getenv("PATH", environ);
	path_arr = str_brk(path, ":");
	len = _strlen(argv[0]);
	while (path_arr[i] != NULL)
	{
		path_len = _strlen(path_arr[i]);
		full_path = malloc(sizeof(char) * (len + path_len + 2));
		_strcpy(full_path, path_arr[i]);
		_strcat(full_path, "/");
		_strcat(full_path, argv[0]);
		_strcat(full_path, "\0");
		if (stat(full_path, &buffer) == 0)
		{
			free_all(path_arr);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}
