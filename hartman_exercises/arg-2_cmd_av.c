#include "holberton.h"

/**
 * main - unknwon
 *
 * Return: Always 0
 */
int main(void)
{
	char str[] = "this is a string";
	const char delim[] = " ";
	char *token;

	for (token = strtok(str, delim); token != NULL; token = strtok(NULL, delim))
		printf("%s\n", token);
	return (0);
}
