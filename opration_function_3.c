#include "monty.h"

/**
 * rotl_f - rotate the stack down.
 * @stack: the stack.
 * @line_number: the line number.
*/
void rotl_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tp = *stack;
	stack_t *tmp = *stack;
	(void)line_number;

	if (!stack || !tp)
		exit(EXIT_FAILURE);

	*stack = (*stack)->next;
	while (tp->next)
		tp = tp->next;

	(*stack)->prev = NULL;
	tp->next = tmp;
	tmp->next = NULL;
	tmp->prev = tp;
}
