#include "shell.h"

/**
 * main - endless loop looking for user input
 * Description: Main entry point to simple holberton shell
 */
int main(int ac, char **av, char **env)
{
	char *s = NULL;
	size_t size = 0;
	pid_t child_pid = 0;
	char **args = NULL;
	int status = 0, history = 0;
	struct stat st;
	/* THESE VARIABLES ARE USED FOR THE FUNCTION THAT TOKENS THE ARGUMENT STRING */
	int tokcount = 0, i = 0;
	char *arg_tmp = NULL;
	char *delim = " \n";
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
		/************** FUNCTION THAT I ADDED ******************/
		/* turn the getline buffer into a series of tokens */
		args = realloc(args, sizeof(char *) * tokcount);
		if (args == NULL)
			return (1); /* CHANGE THIS TO SEND TO ERROR_FUNC */
		arg_tmp = _strtok(s, delim);
		for (i = 0; arg_tmp; i++)
		{
			args[i] = realloc(args[i], sizeof(1) * strlen(arg_tmp) + 1);
			if (args[i] == NULL)
				return (1); /* CHANGE THIS TO SEND TO ERROR */
			strcpy(args[i], arg_tmp);
			arg_tmp = _strtok(NULL, delim);
		}
		args[i] = NULL;
		/************* END FUNCTION *************************/

		child_pid = fork();
		if (child_pid == 0)
		{
			if(stat(args[0], &st) != 0)
			{
				_printf("%s: %d: %s: not found\n", av[0], history, args[0]);
				exit (127);
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
		for( ; tokcount >= 0; tokcount--)
			free(args[tokcount]);
		free(args);
	}
	if (ninter)
		_puts("\n");
	exit (EXIT_SUCCESS);
	return (0);
}

/****************
 * known issues *
 ****************/

/* create fprintf */
/* handle multiple arguments */

/* TO BE COMPLETED COMMENTS ARE CAPITALIZED */

/* all other comments are intended for readibility */
