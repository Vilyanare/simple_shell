#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

int _puts(char *s);
int _strlen(char *s);
int counttok(char *s, char *delim);
char *getkirby(void);
l_env *add_envir(char **env);
size_t list_len(const l_env *h);
l_env *add_node_end(l_env **head, char *s);
void free_listenv(l_env *head);
char *_strdup(char *str);
char *_strchr(char *s, char c);

#endif /* SHELL_H */
