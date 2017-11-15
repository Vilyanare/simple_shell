#include "holberton.h"

/**
 * main - receives a command and prints it on the next line
 * @ac: argument count
 * @av: a pointer to an array of strings
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t size;

	printf("$ ");
	if (getline(&line, &size, stdin) == -1)
		;
	else
		printf("%s", line);

	free(line);
	return (0);
}
