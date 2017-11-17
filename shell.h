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
 * list_environ - Struct for environment linked list
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
 * relations - draws a relationship between a frmt spec and a f-ptr
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


/***********************
 * function prototypes *
 ***********************/
int counttok(char *s, char *delim);
char *getkirby(void);
l_env *add_envir(char **env);
size_t list_len(const l_env *h);
l_env *add_node_end(l_env **head, char *s);
void free_listenv(l_env *head);
/* strings1 functions */
int _puts(char *s);
int _strlen(char *s);
char *_strdup(char *str);
char *_strchr(char *s, char c);
/* strings 2 functions */
int counttok(char *s, char *delim);
char *_strtok(char *s, char *delim);
/* environment handling functions */
size_t list_lenenv(const l_env *h);
void free_listenv(l_env *head);
l_env *add_envir(char **env);
l_env *add_node_endenv(l_env **head, char *s);
void print_envlist(l_env *head);
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
