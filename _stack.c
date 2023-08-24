#include "monty.h"

/**
 * is_numeric - checks if each character is a digit
 * @n: int
 * Return: 0 if is number, -1 if not
 */
int is_numeric(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * _push - adds node to the start of linkedlist
 * @h: head of linked list
 * @line_num: bytecode line number
 * @n: int
 */
void _push(stack_t **h, unsigned int line_num, const char *n)
{
	if (!h)
		return;
	if (is_numeric(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_num);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * _pop - removes node at front of the linkedlist
 * @h: head of linked list
 * @line_num: bytecode line number
 */
void _pop(stack_t **h, unsigned int line_num)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: stack is empty\n", line_num);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}
