#include "shell.h"

/**
 * main - endless loop looking for user input
 * Description: Main entry point to simple holberton shell
 */
int main(int ac, char **av)
{
	char *s = NULL;
	size_t size;
	pid_t child_pid;
	char **args = NULL;
	int status, history = 0;
	struct stat st;
	/* THESE VARIABLES ARE USED FOR THE FUNCTION THAT TOKENS THE ARGUMENT STRING */
	int tokcount, i;
	char **maltemp = NULL;
	char *arg_tmp = NULL;
	char *delim = " \n";
	int ninter = isatty(STDIN_FILENO);

	(void) ac;
	(void) av;

	if (ninter)
		_puts("$ ");
	while (getline(&s, &size, stdin) != -1)
	{
		history++;

		tokcount = counttok(s, delim);
		/************** FUNCTION THAT I ADDED ******************/
		/* turn the getline buffer into a series of tokens */
		maltemp = realloc(args, sizeof(char *) * tokcount);
		if (maltemp == NULL)
			return (1); /* CHANGE THIS TO SEND TO ERROR_FUNC */
		args = maltemp;
		arg_tmp = _strtok(s, delim);
		for (i = 0; arg_tmp; i++)
		{
			maltemp[i] = realloc(args[i], sizeof(1) * strlen(arg_tmp) + 1);
			if (maltemp[i] == NULL)
				return (1); /* CHANGE THIS TO SEND TO ERROR */
			args[i] = maltemp[i];
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
	for( ; tokcount >= 0; tokcount--)
	{
		free(maltemp[i]);
	}
	free(maltemp);
	free(arg_tmp);
	if (ninter)
		_puts("\n");
	exit (EXIT_SUCCESS);
	/* I THINK WE NEED TO FREE THE STRING s SOMEWHERE */
	/* I THINK WE NEED TO FREE args AND args[i] SOMEWHERE CUZ I MALLOCKED */
	return (0);
}

/****************
 * known issues *
 ****************/

/* create fprintf */
/* handle multiple arguments */

/* TO BE COMPLETED COMMENTS ARE CAPITALIZED */

/* all other comments are intended for readibility */
