#include "monty.h"

/**
 * pall - prints all elements in stack
 * @head: head / top of the stack
 * @line_num: the line number
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *curr_top = *head;/* Adjusted to use a double pointer*/
	(void) line_num; /* We need it declared beause of our function*/

	if (head == NULL)
		return;


	while (curr_top)
	{
		printf("%d\n", curr_top->n);
		curr_top = curr_top->next;
	}
}
