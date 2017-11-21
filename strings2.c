#include "shell.h"
/**
 *_strcat - concatenates two strings and puts a / in the middle
 *@s1: first string
 *@s2: second string to add to s1
 *Return: pointer to concatenated string or NULL on failure
 */
char *_strcat(char *s1, char *s2)
{
	int x = _strlen(s1), c = _strlen(s2), i = 0, j = 0;
	int count = _strlen(s1) + _strlen(s2);
	char *p = NULL;

	p = malloc((count + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < x || j < c)
	{
		if (i < x)
		{
			p[i] = s1[i];
			i++;
		}
		else
		{
			p[i + j] = s2[j];
			j++;
		}
	}
	p[i + j] = '\0';
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (p);
}
/**
  * _realloc - reallocates old space to new size (strings only)
  * @ptr: the pointer to the old allocated space of memory
  * @old: size of the old pointer
  * @newsize: The new size wanted in the newly allocated space
  * Return: pointer to the newly allocated space in memory
  */
void *_realloc(void *ptr, int old, int newsize)
{
	void *p;

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
	char *arg_tmp = NULL;

	args = _realloc(args, 0, sizeof(char *) * (tokcount + 1));
	if (args == NULL)
		return (NULL);
	while (i < tokcount)
	{
		args[i] = NULL;
		i++;
	}
	arg_tmp = _strtok(s, delim);
	for (i = 0; i < tokcount; i++)
	{
		args[i] = _realloc(args[i], 0, _strlen(arg_tmp) + 1);
		if (args[i] == NULL)
			return (NULL);
		_strcpy(args[i], arg_tmp);
		arg_tmp = _strtok(NULL, delim);
	}
	args[i] = NULL;
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
	for (count = 0; s[x]; x++)
	{
		if (_strchr(delim, s[x]) && f == 0)
		{
			if (x != 0)
				count++;
			f = 1;
		}
		if (_strchr(delim, s[x]) == 0)
		{
			f = 0;
		}

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
