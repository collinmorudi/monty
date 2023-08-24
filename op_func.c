#include "monty.h"

/**
 * get_op_func - selects the correct function
 * @token1: 1st bytecode
 * Return: pointer to correct function
 */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruction_s[] = {
		{"_pop", _pop},
		{"print_all", print_all},
		{"print_top", print_top},
		{"swap_nodes", swap_nodes},
		{"add_num", add_num},
		{"sub_num", sub_num},
		{"mul_num", mul_num},
		{"div_num", div_num},
		{"mod_num", mod_num},
		{"print_char", print_char},
		{"print_str", print_str},
		{"nothing", nothing},
		{"rotate2", rotate2},
		{"rotate1", rotate1},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
