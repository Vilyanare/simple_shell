#include "shell.h"

/**
 * exit - exits the process
 * @status: a code to determine the status
 * Return: void
 */
void exit_nu(int status)
{
	_exit(status);
}
