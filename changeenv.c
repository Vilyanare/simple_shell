#include "shell.h"
/**
 * _unsetenv - remove an environment variable
 * @vars: variables struct
 */
void _unsetenv(var_t *vars)
{
	l_env *unset = vars->env;
	l_env *next = NULL;
	int f = 1;

	if (vars->args[1])
	{
		if (_strcmp(unset->envvar, vars->args[1]) == 0)
		{
			vars->env = unset->next;
			free(unset->envvar);
			free(unset);
		}
		while (unset->next)
		{
			if (_strcmp(unset->next->envvar, vars->args[1]) == 0)
			{
				next = unset->next->next;
				free(unset->next->envvar);
				free(unset->next);
				unset->next = next;
				f = 0;
				break;
			}
			unset = unset->next;
		}
		if (f)
			_eprintf("Error: %s not found", vars->args[1]);

	}
	else
	{
	_eprintf("Usage: unsetenv VARIABLE\n");
	}
}
/**
 * _setenv - add or change an environment variable
 * @vars: variables struct
 */
void _setenv(var_t *vars)
{
	l_env *env = vars->env;
	l_env *set = NULL;
	char *tmp = NULL;
	int len1 = 0;

	if (vars->args[1] && vars->args[2])
	{
		set = searchenv(env, vars->args[1]);
		tmp = vstrcat(3, vars->args[1], "=", vars->args[2]);
		if (set)
		{
			len1 = _strlen(vars->args[1]);
			free(set->envvar);
			set->envvar = tmp;
			set->envvar[len1] = '\0';
			set->varval = (set->envvar + len1 + 1);
		}
		else
		{
			add_node_endenv(&env, tmp);
			free(tmp);
		}
		if (_strcmp("PATH", vars->args[1]) == 0)
		{
			crte_path(vars);
		}

	}
	else
		_eprintf("Usage: setenv VARIABLE VALUE\n");
}
/**
 * searchenv - search environment list for a variable
 * @head: head of environment linked list
 * @s: variable name
 * Return: address to variable or NULL if not found
 */
l_env *searchenv(l_env *head, char *s)
{
	l_env *found = head;

	while (found)
	{
		if (_strcmp(found->envvar, s) == 0)
			return (found);
		found = found->next;
	}
	return (NULL);
}
