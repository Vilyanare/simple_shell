#include "shell.h"

/**
 * main - main entry point to super simple shell
 * @ac: argument count
 * @av: arguments
 * @env: environment passed from parent
 * Return: exit code 0 for success
 */
int main(int ac, char **av, char **env)
{
	l_var vars = {NULL, NULL, NULL, NULL, 0, NULL, 0, 0, 0};
	size_t size = 0;
	int status = 0;
	char *delim = "\n ";
	int ninter = isatty(STDIN_FILENO);
	vars.av = av[0];

	(void) ac;
	vars.env = add_envir(env);
	crte_path(&vars);
	if (ninter)
		_puts("$ ");
	while (getline(&vars.gets, &size, stdin) != -1)
	{
		vars.hist++;

		vars.args = tokenizer(vars.gets, delim, vars.args);
		vars.tokc = counttok(vars.gets, delim);
		search_path(&vars);
		wait(&status);
		if (ninter)
			_puts("$ ");
	}
	free(vars.gets);
	free_listenv(vars.env);
	if (vars.hist)
	{
		for ( ; vars.tokc >= 0; vars.tokc--)
			free(vars.args[vars.tokc]);
		free(vars.args);
	}
	if (ninter)
		_puts("\n");
	exit(EXIT_SUCCESS);
}
