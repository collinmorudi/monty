#include "monty.h"

/**
 * print_str - print top node in stack as letter
 * @t: top
 * @line_num: bytecode line number
 */
void print_str(stack_t **t, unsigned int line_num)
{
	stack_t *tmp;

	if (!t || !*t)
	{
		printf("L%u: stack is empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *t;
	while ((tmp != NULL) && (tmp->n != 0) &&
		(tmp->n >= 0) && (tmp->n <= 127))
	{
		printf("%c", (tmp)->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * print_top - print top node in the stack
 * @t: top
 * @line_num: bytecode line number
 */
void print_top(stack_t **t, unsigned int line_num)
{
	if (!t || !*t)
	{
		printf("L%u: stack is empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*t)->n);

}
/**
 * print_char - print top node as letter
 * @t: top
 * @line_num: bytecode line number
 */
void print_char(stack_t **t, unsigned int line_num)
{
	if (!t || !*t)
	{
		printf("L%u: stack is empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*t)->n) >= 0 && ((*t)->n) <= 127)
		printf("%c\n", (*t)->n);
	else
	{
		printf("L%u: value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

}

/**
 * print_all - print all nodes in the stack
 * @t: top
 * @line_num: bytecode line number
 */
void print_all(stack_t **t, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (!t || !*t)
		return;

	(void)line_num;
	tmp = *t;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * nothing - do nothing
 * @t: top
 * @line_num: bytecode line number
 */
void nothing(stack_t **t, unsigned int line_num)
{
	(void)t;
	(void)line_num;
}
