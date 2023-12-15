#include "monty.h"

/**
 * pint - prints value at the top of the stack
 * @head: top of the stack
 * @line_num: line number at stack is empty
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
		stack_empty_error(line_num);
	else
	{
		printf("%d\n", (*head)->n);
	}
	(void)line_num;
}
