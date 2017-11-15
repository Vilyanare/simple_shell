#include "holberton.h"

/**
 * main - prints all the arguments
 * @ac: the argument count
 * @av: a pointer to an array of strings
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	unsigned int i;

	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);
	ac = ac;
	return (0);
}
