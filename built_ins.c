#include "shell.h"
/**
 * _sigign - prints a new line when sigint is sent
 * @sig: signal sent
 */
void _sigign(int sig)
{
	if (sig == SIGINT)
		_printf("\n$ ");
}
/**
 * freefunc - frees everything. at exit function
 * @args: l_var struct of things I need to free
 */
void freefunc(var_t *args)
{
	if (args->gets)
		free(args->gets);
	if (args->env)
		free_listenv(args->env);
	if (args->args)
	{
		for (; args->tokc >= 0; args->tokc--)
			free(args->args[args->tokc]);
		free(args->args);
	}
	if (args->path)
	{
		for (; args->ptok >= 0; args->ptok--)
			free(args->path[args->ptok]);
		free(args->path);
	}
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
 * Return: 1 if executed 0 if not found
 */
int pickBuiltIn(var_t *vars)
{
	buil_t blt_ins[] = {
		{"env",  print_envlist},
		{"exit", exit_new},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
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
	{
		f(vars);
		return (1);
	}
	return (0);
}
