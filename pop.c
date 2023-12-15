#include "monty.h"

/**
 * pop - removes the top element off the stack
 * @head: top of the stack
 * @line_num: line number at which stack is empty
 */
void pop(stack_t **head, unsigned int line_num)
{
	if (head == NULL)
		stack_empty_error(line_num);
	else
	{
		*head = (*head)->next;
	}
}
