#ifndef _HEADER_
#define _HEADER_

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

char **str_brk(char *cmd, char *delim);
void free_all(char **ptr_arr);
void sig_handler(int sig_int);
char *build_path(char *cmd);
void processor(char *path, char **argv);
int _exec(char *path, char **argv);

/* environment functions */
char *_getenv(char *name, char **env);

/**
 * struct builtin_func - a structure for builtin fuctions
 * @name: name of builtin command
 * @_name: function of builtin
 */

typedef struct builtin_func
{
	char *name;
	void (*n)(char *cmd, char **argv);
} built_in;

/* functions to manipulate strings */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *z);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* built_in functions */
int check_built(char *cmd, char **argv);
void exit_f(char *cmd, char **argv);

#endif
