#include "monty.h"

/**
 * add_node_end - add node at the end of linked list
 * @h: head
 * @n: node
 * Return: 0 if success, else -1 if
 */
int add_node_end(stack_t **h, int n)
{
	stack_t *new;

	if (!h)
		return (-1);

	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	if (*h == NULL)
	{
		*h = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (0);
}

/**
 * delete_node_end - deletes node at end of linked list
 * @h: head
 */
void delete_node_end(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

/**
 * free_list - frees a linked list
 * @h: head
 */
void free_list(stack_t **h)
{
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
