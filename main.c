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

	(void)ac;
	while (1)
	{
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
		argv = str_brk(input_ptr, delim);
		cmd = argv[0];
		processor(cmd, argv);
		
	}
	free_all(argv);
	free(input_ptr);
	return (0);
}
