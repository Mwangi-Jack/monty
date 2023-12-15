#include "monty.h"

/**
 * operate - a function to select the corresponding operation
 * for the functions
 *
 * @opcode: the first input (opcode
 * Return: a pointer to the corresponding function
 */

void (*operate(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int idx = 0;

	/* based on the received input, we call for our functions*/
	instruction_t instruction_s[] = {
		{"add", add},
		{"nop", nop},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	/* We search through the array of strcuture*/
	while (instruction_s[idx].f != NULL)
	{
		if (strcmp(opcode, instruction_s[idx].opcode) == 0)
			return (instruction_s[idx].f);
		idx++;
	}

	return (NULL);
}
