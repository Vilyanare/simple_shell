#include "shell.h"

/**
 * print_string - prints a string
 * @ap: an argument paramter for a variadic list
 *
 * Return: the count count of characters
 */
int print_string(va_list ap)
{
	int count;
	char *s = va_arg(ap, char *);
	int i;
	char *error = "(null)";

	count = 0;
	if (s == NULL)
		for (i = 0; error[i] != '\0'; i++)
		{
			write(1, &error[i], 1);
			count++;
		}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			write(1, &s[i], 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_integer - prints an integer
 * @ap: an argument parameter for a variadic list
 *
 * Return: the number
 */
int print_integer(va_list ap)
{
	int magnitude;
	unsigned int nu; /* will convert to unsign-int to handle MIN/MAX */
	int n; /* the variable that will hold the va_arg */
	int i;
	char charput; /* cant use putchar, so we write from charput */

	i = 0;
	n = va_arg(ap, int);
	magnitude = 1;
	if (n < 0) /* if the number is negative */
	{
		charput = '-';
		write(1, &charput, 1);
		nu = n * -1;
		i++; /* count the negative sign */
	}
	else
	{
		nu = n * 1; /* convert signed to unsigned int */
	}
	while ((nu / magnitude) >= 10) /* find out the magnitude of the # */
	{
		magnitude *= 10;
	}
	while (magnitude > 0) /* dissect, print each char, count */
	{
		charput = '0' + ((nu / magnitude) % 10);
		write(1, &charput, 1);
		magnitude /= 10;
		i++;
	}
	return (i);
}

/**
 * null_case - deals with instances where function pointer points to null
 * @ch: the char being passed
 *
 * Return: a count
 */
int null_case(char ch)
{
	char aft_pct  = '%';

	if (ch == '%')
	{
		write(1, &ch, 1);
		return (1);
	}
	else if (ch == ' ')
	{
		write(1, &ch, 1);
		return (1);
	}
	else if (ch == '\n')
	{
		write(1, &aft_pct, 1);
		write(1, &ch, 1);
		return (2);
	}
	else
	{
		write(1, &aft_pct, 1);
		write(1, &ch, 1);
		return (2);
	}
	return (0);
}

/**
 * func_pick - chooses the appropriate function to print out various data types
 * @s: the character that determines which print function to use
 *
 * Return: a pointer to a function that takes a va_list and returns an int
 */
int (*func_pick(char s))(va_list)
{
	rela_t relate[] = {
		{'s', print_string},
		{'d', print_integer},
		{'i', print_integer},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (relate[i].ch != '\0')
	{
		if (relate[i].ch == s)
			return (relate[i].fp);
		i++;
	}
	return (relate[i].fp);
}

/**
 * _printf - a proto-printf function
 * @format: the format specifier string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	/* declare variables and structures */
	va_list vl;
	int count;
	int i;
	int (*f)(va_list);

	/* initialize variadic list */
	va_start(vl, format);

	/* loop through the format string */
	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			f = func_pick(format[i]);
			if (f == NULL)
				count += null_case(format[i]);
			else
				count += f(vl);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	/* cleanup then return */
	va_end(vl);
	return (count);
}
