#include "monty.h"

/**
 * rotate1 - rotate bottom node to top
 * @h: node to be rotated
 * @line_num: node number
 */
void rotate1(stack_t **h, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*h) = (*h)->prev;
	}
}

/**
 * rotate2 - rotate so top of stack to the bottom
 * @h: node to be rotated
 * @line_num: node number
 */
void rotate2(stack_t **h, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		(*h)->next->prev = NULL;
		*h = (*h)->next;
		tmp->next->next = NULL;
	}
}

/**
 * swap_nodes - swaps locations of the stack
 * @h: node to be swapped
 * @line_num: node
 */
void swap_nodes(stack_t **h, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap nodes\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->next;
	if (tmp->next != NULL)
	{
		(*h)->next = tmp->next;
		(*h)->next->prev = *h;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *h;
	(*h) = tmp;
}
