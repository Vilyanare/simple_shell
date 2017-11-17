#include "shell.h"
/**
 * envlistfunc.c - a file for handling l_env linked list
 * print_envlist - print l_env 
 * free_listint - frees a l_env linked list
 * list_lenenv - counts length of a l_env linked list
 * add_node_endenv - adds a new node at end of a l_env linked list
 * add_envir - creates a l_env linked list of the environment
 */
/**
 * print_envlist - print l_env string members
 * @head: beginning of list to print
 */
void print_envlist(l_env *head)
{
	_printf("%s=%s\n", head->envvar, head->varval);
	if (head->next)
		print_envlist(head->next);
}
/**
  *free_listint - free a l_env
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
	if (h == NULL)
		return (0);
	if (h->next == NULL)
		return (1);
	else
		return (list_lenenv(h->next) + 1);
}
/**
 *add_node_end - add a new node to end of l_env
 *@head: beginning of list
 *@n: number to add to member n
 *Return: addres of new node
 */
l_env *add_node_endenv(l_env **head, char *s)
{
	l_env *temp = NULL;
	l_env *tail = *head;
	char *tstr = NULL;
	unsigned int x = 0;
	unsigned int c = list_lenenv(*head);

	for (x = 1; x < c; x++)
		tail = tail->next;
	temp = malloc(sizeof(l_env));
	if (temp == NULL)
		return (NULL);
	if (*head == NULL)
		*head = temp;
	else
		tail->next = temp;
	tstr = _strdup(s);
	temp->envvar = _strtok(tstr, "=");
	temp->varval = _strtok(NULL, "=");
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
