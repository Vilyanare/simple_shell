#include "shell.h"
/**
 *_strcmp - compare two strings one character at a time until a difference
 * is encountered.
 *@s1: string one
 *@s2: string two
 *Return: difference between the different chars
 *negative if str 1 is less than str 2
 *positive if str 1 is greater than str 2
 *zero if strings are even
 */
int _strcmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] && s2[c]; c++)
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
	}
	return (0);
}
/**
 *_atoi - converts a string to an integer
 *@vars: variable struct
 *Return: the integer extracted from the string
 */
int _atoi(var_t *vars)
{
	int num = 0, length = 0, x = 1, f = 1, c, end, start = -1;
	char *s = vars->args[1];

	while (s[length])
	{
		if (f == 0 && (s[length] < '0' || s[length] > '9'))
			break;
		if (f && s[length] >= '0' && s[length] <= '9')
		{
			start = length;
			f = 0;
		}
		length++;
		end = length - 1;
	}
	if (start >= 0)
	{
		length = end - start;
		for (c = 0; c <= length; c++)
		{
			num += (s[end - c] - 48) * x;
			if (c == 9)
				break;
			x *= 10;
		}
		return (num);
	}
	else
		return (0);
}
