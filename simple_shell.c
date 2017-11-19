#include "shell.h"
/**
 * main - main entry point to super simple shell
 * @ac: argument count
 * @av: arguments
 * @env: environment passed from parent
 * Return: exit code 0 for success
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	var_t vars = {NULL, NULL, NULL, NULL, 0, NULL, 0, 0, 0, "\n "};
	size_t size = 0;
	int status = 0, ninter = isatty(STDIN_FILENO);	

	vars.av = av[0];
	vars.env = add_envir(env);
	crte_path(&vars);
	if (ninter)
		_puts("$ ");
	while (getline(&vars.gets, &size, stdin) != -1)
	{
		vars.exitstat = EXIT_SUCCESS;
		vars.hist++;
		if (vars.tokc)
			for (; vars.tokc >= 0; vars.tokc--)
				free(vars.args[vars.tokc]);
		vars.tokc = counttok(vars.gets, vars.delim);
		vars.args = tokenizer(vars.gets, vars.delim, vars.args);
		if (vars.gets[0] == '\n')
		{
			if (ninter)
				_puts("$ ");
			continue;
		}
		pickBuiltIn(&vars);
		search_path(&vars);
		wait(&status);
		vars.exitstat = WEXITSTATUS(status);
		if (ninter)
			_puts("$ ");
		free(vars.gets);
		vars.gets = NULL;
	}
	freefunc(&vars);
	if (ninter)
		_puts("\n");
	exit(vars.exitstat);
}
