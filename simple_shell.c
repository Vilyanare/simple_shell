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
	var_t vars = {NULL, NULL, NULL, NULL, 0, NULL, 0, 0, 0, "\n \t"};
	size_t size = 0;
	int status = 0, interactive = isatty(STDIN_FILENO);

	signal(SIGINT, _sigign);
	vars.av = av[0];
	vars.env = add_envir(env);
	crte_path(&vars);
	if (interactive)
		_puts("$ ");
	while (getline(&vars.gets, &size, stdin) != EOF)
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
			if (interactive)
				_puts("$ ");
			continue;
		}
		if (pickBuiltIn(&vars) == 0)
			search_path(&vars);
		wait(&status);
		vars.exitstat = WEXITSTATUS(status);
		if (interactive)
			_puts("$ ");
		free(vars.gets);
		vars.gets = NULL;
	}
	freefunc(&vars);
	if (interactive)
		_puts("\n");
	exit(vars.exitstat);
}
