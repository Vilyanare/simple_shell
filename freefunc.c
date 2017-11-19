#include "shell.h"
/**
 * freefunc - frees everything. at exit function
 * @args: l_var struct of things I need to free
 */
void freefunc(var_t *args)
{
	if (args->gets)
		free(args->gets);
	free_listenv(args->env);
	if (args->hist)
	{
		for (; args->tokc >= 0; args->tokc--)
			free(args->args[args->tokc]);
		free(args->args);
	}
	for (; args->ptok >= 0; args->ptok--)
		free(args->path[args->ptok]);
	free(args->path);
}