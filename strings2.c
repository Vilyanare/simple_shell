#include "shell.h"
/**
  * _realloc - reallocates old space to new size (strings only)
  * @ptr: the pointer to the old allocated space of memory
  * @old: size of the old pointer
  * @newsize: The new size wanted in the newly allocated space
  * Return: pointer to the newly allocated space in memory
  */

void *_realloc(void *ptr, int old, int newsize)
{
	char *p;
	char *temp;
	int i;

	temp = (char *)ptr;
	if (newsize == old)
		return (ptr);
	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (newsize < old)
		old = newsize;
	p = malloc(newsize);
	if (p == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		for (i = 0; i < old; i++)
			p[i] = temp[i];
	}
	free(ptr);
	return (p);
}
/**
 * tokenizer - tokenize a string into an array of strings
 * @s: string to tokenize
 * @delim: delimiter
 * @args: character array
 * Return: pointer to array of tokenized strings
 */
char **tokenizer(char *s, char *delim, char **args)
{
	int tokcount = counttok(s, delim);
	int i = 0;
	static int oldcount = i;
	char *arg_tmp = NULL;

	args = _realloc(args, oldcount * 8, sizeof(char *) * tokcount);
	if (args == NULL)
		return (NULL); /* CHANGE THIS TO SEND TO ERROR_FUNC */
	arg_tmp = _strtok(s, delim);
	for (i = 0; arg_tmp; i++)
	{
		args[i] = _realloc(args[i], _strlen(args[i]), _strlen(arg_tmp) + 1);
		if (args[i] == NULL)
			return (NULL); /* CHANGE THIS TO SEND TO ERROR */
		_strcpy(args[i], arg_tmp);
		arg_tmp = _strtok(NULL, delim);
	}
	args[i] = NULL;
	oldcount = i;
	return (args);
}
/**
 * counttok - Count number tokens in a string
 * @delim: String with delimiters
 * @s: String to count tokens in.
 * Return: number of tokens
 * Description: Can handle multiple delimiters
 */
int counttok(char *s, char *delim)
{
	int count, x = 0, f = 0;

	if (s == NULL)
		return (0);
	for (count = 1; s[x]; x++)
	{
		if (_strchr(delim, s[x]) && f == 0)
		{
			f = 1;
			if (s[x + 1] && x != 0)
				count++;
		}
		else
			f = 0;
	}
	return (count);
}
/**
 * _strtok - tokenize a string based on a delimiter
 * @delim: delimiter
 * @s: string
 * Return: address to beginning of token
 */
char *_strtok(char *s, char *delim)
{
	static char *hold;
	int x = 0, f = 0;

	if (s == 0)
		s = hold;
	if (s == 0)
		return (NULL);
	while (s[x])
	{
		if (_strchr(delim, s[x]))
		{
			if (x == 0 || f == 1)
			{
				s += 1;
				f = 1;
			}
			else if (f == 0)
			{
				s[x] = '\0';
				x++;
				break;
			}
		}
		else
		{
			f = 0;
			x++;
		}
	}
	if (s[x])
		hold = (s + x);
	else
		hold = NULL;
	return (s);
}
