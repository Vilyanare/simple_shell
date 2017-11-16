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
	char **args;
	int status, history = 0;
	struct stat st;
	/* THESE VARIABLES ARE USED FOR THE FUNCTION THAT TOKENS THE ARGUMENT STRING */
	int i;
	int arg_dlm = 0;
	int arg_cnt = 1;
	char *arg_tmp = NULL;
	int ninter = isatty(STDIN_FILENO);

	(void) ac;
	(void) av;

	while (1)
	{
		history++;
		if (ninter)
			_puts("$ ");
		if (getline(&s, &size, stdin) == -1)
		{
			if (ninter)
				_puts("\n");
			exit (EXIT_SUCCESS);
		}

		/************** FUNCTION THAT I ADDED ******************/
		/* turn the getline buffer into a series of tokens */
		i = 0;
		while (s[i])
		{
			if (s[i] == ' ' && arg_dlm == 0)
			{
				arg_dlm = 1;
				arg_cnt++;
			}
			else if (s[i] == '\n' && arg_dlm == 0)
				s[i] = '\0';
			if (s[i] != ' ')
				arg_dlm = 0;
			i++;
		}
		args = malloc(sizeof(char *) * arg_cnt);
		if (args == NULL)
			return (1); /* CHANGE THIS TO SEND TO ERROR_FUNC */
		arg_tmp = strtok(s, " ");
		for (i = 0; arg_tmp; i++)
		{
			args[i] = malloc(sizeof(1) * strlen(arg_tmp) + 1);
			if (args[i] == NULL)
				return (1); /* CHANGE THIS TO SEND TO ERROR */
			strcpy(args[i], arg_tmp);
			arg_tmp = strtok(NULL, " ");
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
			wait(&status);
	}
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
