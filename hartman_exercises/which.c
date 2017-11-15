 qq#include "holberton.h"

/**
 * main - looks for files in the current PATH environment variable
 * @ac: the argument count
 * @av: an array of pointers to the argument(s) string(s)
 * Return: Always 0.
 */

/* why is count initialized at 1? */
/* why do we void ac */
/* is it an issue that we use getenv() when it isnt in the list of approved functions */

int main(int ac, char **av)
{
	int count = 1;     /* a count for the number of tokens */
	int x = 0;     /* an index for looping through arrays */
	int dlmflag = 0;   /* a flag to indicate when we hit a delimiter */
	char *path = NULL; /* a string that will be a copy of the env.var. PATH */
	char *temp = NULL; /* used to point to tokens temporarily */
	char **tokens = NULL; /* a pointer to an array of pointers to strings */
	struct stat st;    /* hold information about a files status */

	(void) ac; /*- 1 -*/
	path = malloc(sizeof(char) * strlen(getenv("PATH")));
	strcpy(path, getenv("PATH"));

	while (path[x]) /*- 2 -*/
	{
		if (path[x] == ':' && dlmflag == 0)
		{
			dlmflag = 1;
			count++;
		}
		if (path[x] != ':')
			dlmflag = 0;
		x++;
	}

	tokens = malloc(sizeof(char *) * count); /*- 3 -*/
	temp = strtok(path, ":");
	for (x = 0; temp; x++)
	{
		tokens[x] = malloc(sizeof(1) * strlen(temp) + strlen(av[1]) + 1);
		strcpy(tokens[x], temp);
		strcat(tokens[x], "/");
		strcat(tokens[x], av[1]);
		temp = strtok(NULL, ":");
	}

	x = 0;
	while (tokens[x])
	{
		if (stat(tokens[x], &st) == 0)
			printf("%s\n", tokens[x]);
		x++;
	}

	free(path);
	free(tokens);
	return (0);
}
/**
 * 1 - we void the argument count for (put reason here)
 *     allocate memory for a copy of the PATH string
 *     then we copy PATH to our copy: path
 * 2 - while a character in path is not equal to the null byte...
 *     if that character is a delimiter and dlmflag is off...
 *     turn on the flag and increase our count of tokens
 *     if that character is not a delimiter, turn the flag off
 * 3 - we allocate memory for an array of pointers
 *     then we assign our tokens to allocated memory
 *     plz note the second sizeof() uses a 1 instead of char to fit in 80 cols.
 */

/**
 * variable names are no longer than 7 characters
 * variable names are descriptive except for loop indices
 * make as portable as possible
 *   make the delimiter a variable
 */
