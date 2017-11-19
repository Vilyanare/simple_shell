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
 * exit_new - exits the process
 * @args: variables struct
 */
void exit_new(var_t *args)
{
	if (args->args[1])
		if (_atoi(args))
			args->exitstat = _atoi(args);
	freefunc(args);
	exit(args->exitstat);
}
/**
 * pickBuiltIn - chooses the appropriate built-in to execute
 * @vars: variable struct
 * Return: function pointer matching string
 */
void (*pickBuiltIn(var_t *vars))(var_t *args)
{
	buil_t blt_ins[] = {
		{"env",  print_envlist},
		{"exit", exit_new},
		{NULL, NULL}
	};
	void (*f)(var_t *args);
	int i;

	for (i = 0; blt_ins[i].usr_str; i++)
	{
		if (_strcmp(blt_ins[i].usr_str, vars->args[0]) == 0)
			break;
	}
	f = blt_ins[i].fnc_ptr;
	if (f)
		f(vars);
	return (blt_ins[i].fnc_ptr);
}
