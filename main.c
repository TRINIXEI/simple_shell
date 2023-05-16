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
	(void)ac, (void)argv;
	char **tokens;
	ssize_t  input;
	char *input_ptr = NULL, *prompt = "$ ", *delim = " \n";
	size_t n = 0;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts(prompt);
		input = getline(&input_ptr, &n, stdin);
		if (input == -1)
		{
			_putchar('\n');
			break;
		}
		tokens = str_brk(input_ptr, delim);
		i = 0;
		while (tokens[i])
		{
			_puts(tokens[i]);
			_putchar('\n');
			i++;
		}
	}
	free(input_ptr);
	return (0);
}
