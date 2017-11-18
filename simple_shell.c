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
	char *s = NULL;
	size_t size = 0;
	pid_t child_pid = 0;
	char **args = NULL;
	int status = 0, history = 0;
	struct stat st;
	int tokcount = 0;
	char *delim = "\n ";
	int ninter = isatty(STDIN_FILENO);
	l_env *environ = NULL;

	(void) ac;
	environ = add_envir(env);
	if (ninter)
		_puts("$ ");
	while (getline(&s, &size, stdin) != -1)
	{
		history++;

		tokcount = counttok(s, delim);
		args = tokenizer(s, delim, args);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (stat(args[0], &st) != 0)
			{
				_printf("%s: %d: %s: not found\n", av[0], history, args[0]);
				exit(127);
			}
			execv(args[0], args);
			/* HANDLE AN ERROR IF EXECV FAILS */
		}
		else
		{
			wait(&status);
			if (ninter)
				_puts("$ ");
		}
	}
	free(s);
	free_listenv(environ);
	if (history)
	{
		for ( ; tokcount >= 0; tokcount--)
			free(args[tokcount]);
		free(args);
	}
	if (ninter)
		_puts("\n");
	exit(EXIT_SUCCESS);
}
