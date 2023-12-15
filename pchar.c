#include "monty.h"

/**
 * pchar - prints character related to the integer
 * at the top of the stack
 * @head: head / top of the stack
 * @line_num: line number at stack is empty
 */
void pchar(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
	(void)line_num;
}
