#include "shell.h"

/**
 * main - entry point of the shell
 * @ac: argument count
 * @argv: argument array
 *
 * Return: int
 */

int main(int ac, char **argv)
{
	ssize_t  input;
	char *input_ptr = NULL, *prompt = "$ ", *delim = " \n", *cmd;
	size_t n = 0;
	int counter = 0, build;
	char **cmd_arr;

	(void)ac;
	while (1)
	{
		counter++;
		signal(SIGINT, sig_handler);
		if (isatty(STDIN_FILENO))
			_puts(prompt);
		input = getline(&input_ptr, &n, stdin);
		if (input == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}
		cmd_arr = str_brk(input_ptr, delim);
		cmd = cmd_arr[0];
		build = check_built(input_ptr, cmd_arr);
		if (build == 1)
			processor(cmd, cmd_arr, argv);
	}
	free_all(cmd_arr);
	free(input_ptr);
	exit(0);
}
