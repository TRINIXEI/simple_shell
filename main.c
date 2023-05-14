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
	ssize_t  input;
	char *input_ptr = NULL, *prompt = "$ ";
	size_t n = 0;

	while (1)
	{
		printf("%s", prompt);
		input = getline(&input_ptr, &n, stdin);
		if (input == -1)
		{
			putchar('\n');
			break;
		}
		printf("%s\n", input_ptr);
	}
	free(input_ptr);
	return (0);
}
