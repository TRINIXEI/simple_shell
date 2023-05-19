#include "shell.h"

/**
 * _getenv - custom function to get environment variable
 * @name: the name of the environment variable
 * @env: environment
 *
 * Return: pointer to value
 */

char *_getenv(char *name, char **env)
{
	int i = 0, len, j;
	char *val = NULL;

	len = _strlen(name);
	while (env[i] != NULL)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] != env[i][j])
				break;
		}
		if (j == len && env[i][j] == '=')
		{
			val = env[i] + len + 1;
			return (val);
		}
		i++;
	}
	return (NULL);
}
