#include "monty.h"

/**
 * mul - muls first two elements on stack
 * @head: head of the dll
 * @line_num: the line number of the error instruction
 */

void mul(stack_t **head, unsigned int line_num)
{
	int muli;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	muli = (*head)->next->n * (*head)->n;
	(*head)->next->n = muli;

	*head = (*head)->next;
	(*head)->prev = NULL;
	free_dll(head);
}
