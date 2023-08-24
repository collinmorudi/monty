#include "monty.h"
/**
 * add_num - adds the top two elements in the stack
 * @t: top
 * @line_num: node number
 */
void add_num(stack_t **t, unsigned int line_num)
{
	if (*t == NULL || (*t)->next == NULL)
	{
		printf("L%u: can't perfom addition\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*t)->next->n += (*t)->n;
	(*t) = (*t)->next;
	free((*t)->prev);
	(*t)->prev = NULL;
}
/**
 * sub_num - subtract second node from the top node
 * @t: top
 * @line_num: line of command
 */
void sub_num(stack_t **t, unsigned int line_num)
{
	if (*t == NULL || (*t)->next == NULL)
	{
		printf("L%u: can't perform sub\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*t)->next->n -= (*t)->n;
	(*t) = (*t)->next;
	free((*t)->prev);
	(*t)->prev = NULL;
}
/**
 * mul_num - multiply second node and top node
 * @t: top
 * @line_num: line of command
 */
void mul_num(stack_t **t, unsigned int line_num)
{
	if (*t == NULL || (*t)->next == NULL)
	{
		printf("L%u: can't perform mul\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*t)->next->n *= (*t)->n;
	(*t) = (*t)->next;
	free((*t)->prev);
	(*t)->prev = NULL;
}

/**
 * div_num - divides second node from top node
 * @t: top
 * @line_num: line of command
 */
void div_num(stack_t **t, unsigned int line_num)
{
	if (*t == NULL || (*t)->next == NULL)
	{
		printf("L%u: can't perfom div\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*t)->n == 0 || (*t)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_num);
	}
	(*t)->next->n /= (*t)->n;
	(*t) = (*t)->next;
	free((*t)->prev);
	(*t)->prev = NULL;
}

/**
 * mod_num - mod second node from top node
 * @t: top
 * @line_num: line of command
 */
void mod_num(stack_t **t, unsigned int line_num)
{
	if (t == NULL || *t == NULL)
	{
		printf("L%u: can't perform mod\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*t)->n == 0 || (*t)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_num);
	}
	(*t)->next->n %= (*t)->n;
	(*t) = (*t)->next;
	free((*t)->prev);
	(*t)->prev = NULL;
}
