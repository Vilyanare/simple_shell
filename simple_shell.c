#include "shell.h"
/**
 * main - endless loop looking for user input
 * Description: Main entry point to simple holberton shell
 */
/* sh: 1: ./././ls: not found */
int main(int ac, char **av)
{
	char *s = NULL;
	size_t size;
	pid_t child_pid;
	char *args[2];
	int status, history = 0;
	struct stat st;

	(void) ac;
	(void) av;
	
	while (1)
	{
		history++;
		_puts("$ ");
		if (getline(&s, &size, stdin) < 1)
		{
			_puts("\n");
			exit (EXIT_SUCCESS);
		}
		args[0] = strtok(s, "\n");
		args[1] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			if(stat(args[0], &st) != 0)
			{
				printf("%s: %d: %s: not found\n", av[0], history, args[0]);
				exit (127);
			}
			execv(args[0], args);
		}
		else
		{
			wait(&status);
		}
	}
}
