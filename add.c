#include "monty.h"

/**
 * add - adds first two elements on stack
 * @head: head of the dll
 * @line_num: the line number of the error instruction
 */

void add(stack_t **head, unsigned int line_num)
{
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;


	*head = (*head)->next;
	(*head)->prev = NULL;
	free_dll(head);
}
