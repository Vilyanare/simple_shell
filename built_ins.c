#include "shell.h"

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
