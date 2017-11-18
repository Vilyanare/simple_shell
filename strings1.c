#include "shell.h"
/**
 **_strcpy - copies string from src to dest
 *@dest: address to put string
 *@src: address to take string from
 *Return: char pointer
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x]; x++)
		dest[x] = src[x];
	dest[x] = '\0';
	return (dest);
}
/**
 * _strlen - Find the length of a null terminated string
 * @s: Input string
 * Return: Length of string
 */
int _strlen(char *s)
{
	int x = 0;

	if (s == NULL)
		return (0);
	for (; s[x]; x++)
		;
	return (x);
}
/**
 * _puts - Writes a string to standard output
 * @s: String to write
 * Return: how many characters were written
 */
int _puts(char *s)
{
	return (write(1, s, _strlen(s)));
}
/**
 *_strchr - finds provided char in string
 *@s: string to search
 *@c: character to find
 *Return: pointer to first occurance of character
 */
char *_strchr(char *s, char c)
{
	int x;

	for (x = 0; s[x]; x++)
	{
		if (s[x] == c)
			return (s + x);
	}
	if (c == '\0')
		return (s + x);
	return (NULL);
}
/**
 *_strdup - copies string to new location
 *@str: string to be copied
 *Return: pointer to new string
 */
char *_strdup(char *str)
{
	int x;
	char *p = NULL;

	if (str == NULL)
		return (NULL);
	for (x = 0; str[x]; x++)
		;
	p = malloc((x + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (x = 0; str[x]; x++)
		p[x] = str[x];
	p[x] = '\0';
	return (p);
}
