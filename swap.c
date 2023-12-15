#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: head / top of the stack
 * @line_num: line number at which swap was called
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *node = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		free_dll(head);
		exit(EXIT_FAILURE);
	}

	node = (*head)->next;

	if (node->next != NULL)
	{
		(*head)->next = node->next;
		(*head)->next->prev = *head;
	}
	else
	{
		node->prev->prev = node;
		node->prev->next = NULL;
	}

	node->prev = NULL;
	node->next = *head;
	(*head)->prev = node;
	(*head) = node;
}
