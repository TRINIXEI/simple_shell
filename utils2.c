#include "shell.h"

/**
 * _atoi - A string should be convert to an integer.
 * @z: The pointer to convert
 * Return: Integer
 */
int _atoi(char *z)
{
	int k = 0;
	unsigned int fd = 0;
	int lil = 0;
	int mid = 1;

	while (z[k])
	{
		if (z[k] == 45)
		{
			mid *= -1;
		}
		while (z[k] >= 48 && z[k] <= 57)
		{
			lil = 1;
			fd = (fd * 10) + (z[k] - '0');
			k++;
		}
		if (lil == 1)
		{
			break;
		}
		k++;
	}
	fd *= mid;
	return (fd);
}

/**
 * _strcmp - compares two strings values
 * @s1: string 1
 * @s2: string 2
 * Return: the difference in s2 and s1
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	j = 0;
	while (s1[j] != '\0' && s2[j] !=  '\0')
	{
		if (s1[j] != s2[j])
		{
			return (s1[j] - s2[j]);
		}
	j++;
	}
	return (0);
}
