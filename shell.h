#ifndef SHELL_H_
#define SHELL_H_


#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdio.h>

/**
 * struct my_variables - Structure containing various variables
 * @av: Command line arguments
 * @buffer: Buffer for command input
 * @env: Environment variables
 * @count: Count of commands entered
 * @argv: Arguments at the opening of the shell
 * @status: Exit status
 * @commands: Double pointer to commands
 */

typedef struct my_variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;
/**
 * struct my_builtins - Structure for the builtin functions
 * @name: Name of the builtin command
 * @f: Function pointer for the corresponding builtin
 */

typedef struct my_builtins
{
	char *name;
	void (*f)(vars_t *);
} my_bins;


char **mylock_find(char **myenv, char *mykey);
char *value_add(char *mykey, char *myvalue);
int my_latoi(char *mystr);

void pathCheck(vars_t *myvars);
int pathExe(char *mycommand, vars_t *myvars);
char *pathFind(char **myenv);
int cwdExe(vars_t *myvars);

int directory_check(char *mystr);
void errorPrint(vars_t *myvars, char *mymsg);
void puts4(char *mystr);
char *uitoa(unsigned int mycount);

char **environ_create(char **myenv);
void environ_clear(char **myenv);
ssize_t puts(char *strng);
char *dupstr(char *mystrtodup);

int cmprstr(char *mystrcmp1, char *mystrcmp2);
char *strcat(char *mystrc1, char *mystrc2);
unsigned int strlength(char *strng);

char **my_token(char *buff, char *mydlimiter);
char **rellocat(char **myptr, size_t *mysize);
char *strtoken(char *mystr, const char *mydelim);

void (*checkbins(vars_t *myvars))(vars_t *myvars);
void exit(vars_t *myvars);
void my_env(vars_t *myvars);

void set_environ(vars_t *myvars);
void unset_environ(vars_t *myvars);
void key_add(vars_t *myvars);

#endif
