#include "shell.h"

/**
 * exit - exits the process
 * @status: a code to determine the status
 * Return: void
 */
void exit_new(var_t *args)
{
	freefunc(args);
	exit(args->exitstat);
}
