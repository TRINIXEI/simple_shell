#include "shell.h"

/**
 * processor - evaluates the command entered
 * @path: the built path
 * @argv: arguments array
 *
 * Return: void
 */

void processor(char *path, char **argv)
{
	char *command = build_path(path);

	if (path == NULL || argv == NULL)
	{
		/* _putchar('\n'); */
	}
	else if (command != NULL)
	{
		_exec(command, argv);
	}
	else
		printf("none works\n");
}

/**
 * _exec - execute an executable file
 * @path: first command
 * @argv: argument variable
 *
 * Return: int
 */

int _exec(char *path, char **argv)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == -1)
	{
		perror("/hsh");
		return (1);
	}
	else if (child == 0)
	{
		if (execve(path, argv, environ) == -1)
			perror("/hsh");
	}
	else
	{
		wait(&stat);
	}
	return (0);
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
 * @cmd: argument variable
 *
 * Return: full path
 */

char *build_path(char *cmd)
{
	char *path, *p_cpy, *full_path, *p_token;
	struct stat buff;
	int len, p_len;

	if (cmd == NULL)
		return (NULL);
	path = _getenv("PATH", environ);
	if (path == NULL)
	{
		perror("/hsh: error");
		return (NULL);
	}
	p_cpy = strdup(path);
	len = _strlen(cmd);
	p_token = strtok(p_cpy, ":");
	while (p_token != NULL)
	{
		p_len = _strlen(p_token);
		full_path = malloc(sizeof(char) * (p_len + len + 2));
		_strcpy(full_path, p_token);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &buff) == 0)
		{
			free(p_cpy);
			return (full_path);
		}
		else
		{
			free(full_path);
			p_token = strtok(NULL, ":");
		}
	}
	free(p_cpy);
	if (stat(cmd, &buff) == 0)
		return (cmd);
	return (NULL);
}
