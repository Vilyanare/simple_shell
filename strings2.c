#include "shell.h"
/**
 * strings2.c - more string functions
 * counttok: count tokens in an untokenized string
 * _strintok: tokenize a string
 */

/**
 * counttok - Count number tokens in a string
 * @delim: String with delimiters
 * @s: String to count tokens in.
 * Return: number of tokens
 * Description: Can handle multiple delimiters
 */
int counttok(char *s, char *delim)
{
	int count, x = 0;
	
	if (s == NULL)
		return (0);
	for (count = 1; s[x]; x++)
	{
		if (_strchr(delim, s[x]))
			count++;
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
	int x = 0;

	if (s == 0)
		s = hold;
	if (s == 0)
		return (NULL);
	while (s[x])
	{
		if (_strchr(delim, s[x]))
		{
			s[x] = '\0';
			x++;
			break;
		}
		x++;
	}
	if (s[x])
		hold = (s + x);
	else
		hold = NULL;
	return (s);
}
