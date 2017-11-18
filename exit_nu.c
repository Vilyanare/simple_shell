#include "shell.h"

/**
 * exit - exits the process
 * @status: a code to determine the status
 * Return: void
 */
void exit_new(l_var *args)
{
	_exit(args->exitstat);
}
