#include "monty.h"

/**
 * push - pushed an element to a stack
 * @head: top of stack
 * @data: data to push to stack
 * @line_num: the line number
 */
void push(stack_t **head, unsigned int line_num, const char *data)
{
	int i = 0;

	if (!head)
		return;

	if (data == NULL || *data == '\0')
		i = -1;
	else if (data[i] == '-' || data[i] == '+')
		i++;

	while (data[i] != '\0')
	{
		if (!isdigit(data[i]))
		{
			i = -1;
			break;
		}
		i++;
	}

	if (i == -1 || add_node(head, atoi(data)) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_dll(head);
		exit(EXIT_FAILURE);
	}
}
