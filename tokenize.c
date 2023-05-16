#include "shell.h"

/**
 * brk_str - breaking string into tokens
 * @cmd: command to break
 * @delim: delimiter to use
 *
 * Return: pointer to an array of pointers
 */

char **str_brk(char *cmd, char *delim)
{
	char *token, *cmd_cpy =  NULL;
	char **arr_ptr;
	int tok_count = 0, len, i, cmd_len;

	cmd_len = strlen(cmd);
	cmd_cpy = malloc(sizeof(char) * cmd_len);
	if (cmd_cpy == NULL)
	{
		printf("cmd_cpy error\n");
		return (NULL);
	}
	strcpy(cmd_cpy, cmd);
	token = strtok(cmd, delim);
	while (token != NULL)
	{
		tok_count++;
		token = strtok(NULL, delim);
	}
	tok_count++;
	arr_ptr = malloc(sizeof(char *) * tok_count);
	if (arr_ptr == NULL)
	{
		printf("arr-ptr error\n");
		return (NULL);
	}
	token = strtok(cmd_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		len =  strlen(token);
		arr_ptr[i] = malloc(sizeof(char) * len);
		if (arr_ptr[i] == NULL)
		{
			printf("arr_ptr[i] error\n");
			return (NULL);
		}
		strcpy(arr_ptr[i], token);
		token = strtok(NULL, delim);
	}
	arr_ptr[i] = NULL;
	free(cmd_cpy);
	return (arr_ptr);
}
