#include "monty.h"

/**
 * pall - prints all elements in stack
 * @head: top of the stack
 * @line_num: the line number
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *curr_top = *head;
	(void) line_num;

	if (head == NULL)
		return;


	while (curr_top)
	{
		printf("%d\n", curr_top->n);
		curr_top = curr_top->next;
	}
}
