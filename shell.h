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
int processor(char **argv);
void sig_handler(int sig_int);
char *build_path(char **argv);

/* environment functions */
char *_getenv(char *name, char **env);

/* functions to manipulate strings */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *z);
int _strcmp(char *s1, char *s2);

#endif
