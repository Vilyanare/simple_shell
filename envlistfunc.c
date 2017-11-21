#include "shell.h"
/**
 * print_envlist - print l_env string members
 * @vars: variables struct
 */
void print_envlist(var_t *vars)
{
	l_env *head = vars->env;

	while (head)
	{
		_printf("%s=%s\n", head->envvar, head->varval);
			head = head->next;
	}
}
/**
  *free_listenv - free a l_env
  *@head: beginning of list
  */
void free_listenv(l_env *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_listenv(head->next);
		free(head->envvar);
		free(head);
	}
}
/**
 *list_lenenv - returns number of elements in a l_env
 *@h: list to count
 *Return: Nodes in list
 */
size_t list_lenenv(const l_env *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);
	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
/**
 *add_node_end - add a new node to end of l_env
 *@head: beginning of list
 *@s: string to add to member
 *Return: addres of new node
 */
l_env *add_node_endenv(l_env **head, char *s)
{
	l_env *temp = NULL;
	l_env *tail = *head;
	char *tstr = NULL;
	char *deli = NULL;
	unsigned int x = 0;
	unsigned int c = list_lenenv(*head);

	for (x = 1; x < c; x++)
		tail = tail->next;
	temp = malloc(sizeof(struct list_environ));
	if (temp == NULL)
		return (NULL);
	if (*head == NULL)
		*head = temp;
	else
		tail->next = temp;
	tstr = _strdup(s);
	deli = _strchr(tstr, '=');
	temp->envvar = tstr;
	deli[0] = '\0';
	temp->varval = (deli + 1);
	temp->next = NULL;
	return (temp);
}
/**
 * add_envir - Make a linked list of parent environment settings
 * @env: Environment array from parent
 * Return: Address to head of list
 */
l_env *add_envir(char **env)
{
	l_env *head = NULL;
	int x = 0;

	while (env[x])
	{
		add_node_endenv(&head, env[x]);
		x++;
	}
	return (head);
}
