#include "monty.h"

/**
 * mod - mods first two elements on stack
 * @head: head of the dll
 * @line_num: the line number of the error instruction
 */

void mod(stack_t **head, unsigned int line_num)
{
	int mod_ans;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	mod_ans = (*head)->next->n % (*head)->n;
	(*head)->next->n = mod_ans;


	*head = (*head)->next;
	(*head)->prev = NULL;
	free_dll(head);
}
