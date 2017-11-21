#include "shell.h"
/**
 * crte_path - create the path array
 * @vars: variable struct
 */
void crte_path(var_t *vars)
{
	l_env *head = vars->env;

	while (head->next)
	{
		if (_strcmp(head->envvar, "PATH") == 0)
		{
			vars->ptok = counttok(head->varval, ":");
			vars->path = tokenizer(head->varval, ":", vars->path);
			break;
		}
		head = head->next;
	}

}
/**
 * search_path - look in PATH for functions and execute them
 * @vars: variable struct
 */
void search_path(var_t *vars)
{
	pid_t child_pid = 0;
	struct stat st;
	int x = 0;
	char *temp = NULL;
	char *s = vars->args[0];

	while (vars->path[x])
	{
		if (vars->args[0][0] == '.' && vars->args[0][1] == '/')
			break;
		temp = vstrcat(3, vars->path[x], "/", vars->args[0]);
		if (stat(temp, &st) == 0 && S_ISREG(st.st_mode))
		{
			free(vars->args[0]);
			vars->args[0] = _strdup(temp);
			free(temp);
			break;
		}
		x++;
		free(temp);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (stat(vars->args[0], &st))
		{
			_eprintf("%s: %d: %s: not found\n", vars->av, vars->hist, s);
			exit(127);
		}
		if (S_ISREG(st.st_mode) == 0)
		{
			_eprintf("%s: %d: %s: Permission denied\n", vars->av, vars->hist, s);
			exit(126);
		}
		execv(vars->args[0], vars->args);
	}
}
