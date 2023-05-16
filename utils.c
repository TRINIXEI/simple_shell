#include "shell.h"
#include "unistd.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* _puts - prints a string, followed by a new line, to stdout
*  @str: string to print
*/
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
* _strlen - function that returns the length of a string
* @n: input
* Return: n
*/
int _strlen(char *n)
{
	int longi = 0;

	while (*n != '\0')
	{
		longi++;
		n++;
	}
	return (longi);
}

/**
* _strcpy - copy a string
* @dest: Destination value
* @src: Source value
* Return: the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int k;

	for (k = 0; src[k] != '\0'; k++)
	{
		dest[k] = src[k];
	}
	dest[k++] = '\0';
	return (dest);
}

/**
* _strcat - concatenates two string
* @dest: input value
* @src: input value
*
* Return: void
*/
char *_strcat(char *dest, char *src)
{
	int g;
	int z;

	g = 0;
	while (dest[g] != '\0')
	{
		g++;
	}
	z = 0;
	while (src[z] != '\0')
	{
		dest[g] = src[z];
		g++;
		z++;
	}
	dest[g] = '\0';
	return (dest);
}
