#include "monty.h"

/**
 * add_node_end - adds a node at the end of the stack
 * @stack: stack
 * @new_node: node to add to the linked list
 *
 * Return: void
 */
void add_node_end(stack_t **stack, stack_t **new_node)
{
	stack_t *curr;

	(*new_node)->n = atoi(head.args);
	(*new_node)->next = NULL;
	if (*stack == NULL)
	{
		(*new_node)->prev = NULL;
		*stack = *new_node;
	}
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		(*new_node)->prev = curr;
		curr->next = *new_node;
		curr = *new_node;
	}
}
