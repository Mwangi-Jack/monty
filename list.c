#include "monty.h"

/**
 * add_node - add node to linked list
 * @head: pointer to head of the linked list
 * @data: node data
 * Return: 0 if success, -1 if failed
 */
int add_node(stack_t **head, int data)
{
	stack_t *new_node = malloc(sizeof(struct stack_s));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}

	new_node->n = data;

	if (*head)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}

	new_node->prev = NULL;
	*head = new_node;

	return (0);
}


/**
 * free_dll - frees a doubly linked list
 * @head: pointer to head of list
 */

void free_dll(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		stack_t *next_node = (*head)->next;

		free(*head);
		*head = next_node;
	}
	free(*head);
	*head = NULL;
}
