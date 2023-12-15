#include "monty.h"

/**
 * divide - divides first two elements on stack
 * @head: head of the dll
 * @line_num: the line number of the error instruction
 */

void divide(stack_t **head, unsigned int line_num)
{
	int dividei;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't divide, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: divideision by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	dividei = (*head)->next->n / (*head)->n;
	(*head)->next->n = dividei;


	*head = (*head)->next;
	(*head)->prev = NULL;
	free_dll(head);
}
