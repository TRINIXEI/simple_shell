#include "niceflow.h"

/**
 * create_envi - A function that creates an array of Enviroment Variables
 * @envi: Array to store Enviroment Variables
 */

void create_envi(char **envi)
{
	int crt_envr;

	for (crt_envr = 0; environ[crt_envr]; crt_envr++)
		envi[crt_envr] = _strdup(environ[crt_envr]);
	envi[crt_envr] = NULL;
}

/**
 * free_env - A function that frees the memory of
 * the created Enviroment Variables array
 * @env:  Array of Environment variables
 */

void free_env(char **env)
{
	int crt_envr;

	for (crt_envr = 0; env[crt_envr]; crt_envr++)
	{
		free(env[crt_envr]);
	}
}
