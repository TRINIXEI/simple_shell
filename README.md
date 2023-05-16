Documentation for Simple Shell project, a custom shell project built using C programming Language.

* Contributors:
	- Charles Okechukwu
	- Eunice Oladeji

* Requirements:
- Simple_shell is designed to run on Ubuntu 14.04 LTS linux environment and it is compliled using GNU compiler `gcc` with the flags `-Wall, -Werror, -Wextra and -pedantic`

* Usage:
- This Simple_shell is programmed to execute commands in a similar manner to sh, however with a more limited functionality. It can be executed 	by typing in the command `./sh`
* License:
- This is an open source project to fufil the requirements of Software Engineering in ALX bootcamp, its free to use
* Contents:
	README.md - Contins the descriptive text and light documentations of all the datails of this simple_shell program.
	AUTHORS - Contains the names and emails of the authors and contributors of this program
	- Main.c - entry point of the shell, contains the function that launches the shell prompt
	- tokenize.c - contains the function `str_brk` that breaks commands and returns an aray of pointers
	- utils.c - contains all custom functions such as `_putchar _puts _strlen _strcpy _strcat` used in building simple shell
