#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opcodes related prototypes */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_num);
void _push(stack_t **h, unsigned int line_num, const char *n);
void _pop(stack_t **h, unsigned int line_num);
void print_top(stack_t **t, unsigned int line_num);
void print_all(stack_t **t, unsigned int line_num);
void swap_nodes(stack_t **h, unsigned int line_num);
void nothing(stack_t **t, unsigned int line_num);
void print_char(stack_t **t, unsigned int line_num);
void print_str(stack_t **t, unsigned int line_num);
void rotate2(stack_t **h, unsigned int line_num);
void rotate1(stack_t **h, unsigned int line_num);

/* calculator prototypes */
void add_num(stack_t **t, unsigned int line_num);
void sub_num(stack_t **t, unsigned int line_num);
void mul_num(stack_t **t, unsigned int line_num);
void div_num(stack_t **t, unsigned int line_num);
void mod_num(stack_t **t, unsigned int line_num);

/* doubly linked list related prototypes */
int add_node_end(stack_t **h, int n);
void delete_node_end(stack_t **h);
void free_list(stack_t **h);

#endif
