#include "monty.h"

/**
 * pstr - prints character related to the integer
 * at the top of the stack
 * @head: head / top of the stack
 * @line_num: line number at stack is empty
 */
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *curr_top = *head;/* Adjusted to use a double pointer*/
	(void) line_num; /* We need it declared beause of our function*/

	if (*head == NULL)
	{
		printf("\n");
		return;
	}

	while (curr_top)
	{
		if ((*head)->n <= 0 || (*head)->n > 127)
		{
			break; /* break out of the loop */
		}
		printf("%c", curr_top->n);
		curr_top = curr_top->next;
	}
	printf("\n");
}
