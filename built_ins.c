#include "shell.h"
/**
 * freefunc - frees everything. at exit function
 * @args: l_var struct of things I need to free
 */
void freefunc(var_t *args)
{
	if (args->gets)
		free(args->gets);
	free_listenv(args->env);
	if (args->hist)
	{
		for (; args->tokc >= 0; args->tokc--)
			free(args->args[args->tokc]);
		free(args->args);
	}
	for (; args->ptok >= 0; args->ptok--)
		free(args->path[args->ptok]);
	free(args->path);
}
/**
 * exit - exits the process
 * @status: a code to determine the status
 * Return: void
 */
void exit_new(var_t *args)
{
	freefunc(args);
	exit(args->exitstat);
}
/**
 * pickBuiltIn - chooses the appropriate built-in to execute
 * @usr_str: the built-in command to run, which was entered by user
 *
 * Return: a pointer to a built-in program
 */
void (*pickBuiltIn(char *s))(var_t *args)
{
	buil_t blt_ins[] = {
		{"env",  print_envlist},
		{"exit", exit_new},
		{NULL, NULL}
	};
	int i;

	for (i = 0; blt_ins[i].usr_str; i++)
	{
		if (_strcmp(blt_ins[i].usr_str, s) == 0)
			break;
	}
	return (blt_ins[i].fnc_ptr);
}
