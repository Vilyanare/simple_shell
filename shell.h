#ifndef SHELL_H
#define SHELL_H


/****************************
 * directives and libraries *
 ****************************/
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
} l_var;

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

typedef struct builtin_pointers
{
	char *usr_str;
	void (*fnc_ptr)(/* struct name goes here */);
} buil_t;


/***********************
 * function prototypes *
 ***********************/
char *getkirby(void);
/* built-in functions */

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
/* environment handling functions */
size_t list_lenenv(const l_env *h);
void free_listenv(l_env *head);
l_env *add_envir(char **env);
l_env *add_node_endenv(l_env **head, char *s);
void print_envlist(l_var *vars);
/* path handling functions */
void search_path(l_var *vars);
void crte_path(l_var *vars);
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
