#include "holberton.h"

/**
 * main - initiates the shell
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[2];
	char *line = NULL;
	size_t size;

	argv[1] = NULL;
	while (1)
	{
		/* prompt and get line */
		printf("#cisfun$ ");
		if (getline(&line, &size, stdin) == -1)
		{
			printf("Error: getline\n");
			return (0);
		}
		argv[0] = strtok(line, "\n");

		/* create child process */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			break;
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
