#include "holberton.h"

/**
 * print the environment using the global variable environ
 */
int main(int ac, char **av, char **env)
{
	int i;
	extern char **environ;

	printf("env address: %p\nenviron address: %p\n\n", &env, &environ);
	printf("env value: %p\nenviron value: %p\n\n", env, environ);
	printf("ac address: %p\nav address: %p\n\n", &ac, &av);
	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (0);
}
