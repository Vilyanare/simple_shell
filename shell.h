#ifndef SHELL_H
#define SHELL_H


/****************************
 * directives and libraries *
 ****************************/
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdarg.h>


/**************
 * structures *
 **************/
/**
 * struct list_environ - Struct for environment linked list
 * @envvar: Variable name
 * @varval: Value of variable
 * @next: Next node in list
 */
typedef struct list_environ
{
	char *envvar;
	char *varval;
	struct list_environ *next;
} l_env;

/**
 * struct variables - struct for global variables
 * @gets: getline string
 * @env: head of our environment linked list
 * @args: tokenized argument array
 * @path: tokenized path array
 * @tokc: how many tokens in args
 * @av: name of program
 * @hist: how many lines have been executed
 * @ptok: path token count
 * @exitstat: exit status to send to error program
 * @delim: delimiter string to determine tokens
 */
typedef struct variables
{
	char *gets;
	l_env *env;
	char **args;
	char **path;
	int tokc;
	char *av;
	int hist;
	int ptok;
	int exitstat;
	char *delim;
} var_t;
/**
 * struct relations - draws a relationship between a frmt spec and a f-ptr
 * @ch: the format specifier
 * @fp: a pointer to a function that takes in a type va_list and returns an int
 *
 * Description: This struct is used for printf.
 *    ch will be the primary format specifier ie not a flag!
 */
typedef struct relations
{
	char ch;
	int (*fp)(va_list);
} rela_t;
/**
 * struct builtin_pointers - struct to handle builtins
 * @usr_str: string to match to user input
 * @fnc_ptr: function to execute on match
 */
typedef struct builtin_pointers
{
	char *usr_str;
	void (*fnc_ptr)(var_t *args);
} buil_t;


/***********************
 * function prototypes *
 ***********************/
char *getkirby(void);
/* built-in functions */
void exit_new(var_t *args);
int pickBuiltIn(var_t *vars);
/* strings1 functions */
char *_strcpy(char *dest, char *src);
int _puts(char *s);
int _strlen(char *s);
char *_strdup(char *str);
char *_strchr(char *s, char c);
/* strings 2 functions */
char *_strcat(char *s1, char *s2);
void *_realloc(void *ptr, int old, int newsize);
char **tokenizer(char *s, char *delim, char **args);
int counttok(char *s, char *delim);
char *_strtok(char *s, char *delim);
/* strings 3 functions */
int _strcmp(char *s1, char *s2);
int _atoi(var_t *vars);
char *vstrcat(int num, ...);
/* environment initialize functions */
size_t list_lenenv(const l_env *h);
void free_listenv(l_env *head);
l_env *add_envir(char **env);
l_env *add_node_endenv(l_env **head, char *s);
void print_envlist(var_t *vars);
/* functions to change env */
void _setenv(var_t *vars);
void _unsetenv(var_t *vars);
l_env *searchenv(l_env *head, char *s);
/* path handling functions */
void search_path(var_t *vars);
void crte_path(var_t *vars);
/* exit handling */
void _sigign(int sig);
void freefunc(var_t *args);
/* _printf functions */
int _printf(const char *format, ...);
int (*func_pick(char s))(va_list);
int print_string(va_list);
int print_number(va_list);
int null_case(char);
/* _eprintf functions */
int _eprintf(const char *format, ...);
int (*efunc_pick(char s))(va_list);
int eprint_string(va_list);
int eprint_number(va_list);
int enull_case(char);


#endif /* SHELL_H */
