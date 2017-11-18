#include "shell.h"

/**
 * pickBuiltIn - chooses the appropriate built-in to execute
 * @usr_str: the built-in command to run, which was entered by user
 *
 * Return: a pointer to a built-in program
 */
void (*pickBuiltIn(char *s))(/* PUT STRUCT PARAM HERE */)
{
	buil_t blt_ins[] = {
		{"env",  print_envlist},
		{"exit", exit},
		{NULL, NULL}
	};
	int i;

	for (i = 0; blt_ins[i].usr_str != NULL; i++)
	{
		if (blt_ins[i].usr_str == s)
			break;
	}
	return (blt_ins[i].fnc_ptr);
}
