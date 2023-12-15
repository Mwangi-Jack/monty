#include "monty.h"

/**
 * sub - subs first two elements on stack
 * @head: head of the dll
 * @line_num: the line number of the error instruction
 */

void sub(stack_t **head, unsigned int line_num)
{
	int diff;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	diff = (*head)->next->n - (*head)->n;
	(*head)->next->n = diff;


	*head = (*head)->next;
	(*head)->prev = NULL;
	free_dll(head);
}
