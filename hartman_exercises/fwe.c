#include "holberton.h"

/**
 * main - executes the command ls -l /tmp in 5 different child
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	unsigned int index;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (index = 0; index < 5; index++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
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

/*
{
	char *av[] = {"/bin/ls", "-l", "/tmp/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error:");
	printf("After execve\n");
	return (0);
}
*/
