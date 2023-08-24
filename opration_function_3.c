#include "monty.h"

/**
 * rotl_f - rotate the stack down.
 * @stack: the stack.
 * @line_number: the line number.
*/
void rotl_f(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tp = *stack;
	stack_t *tmp = *stack;

	if (!stack || !tp)
		nop(stack, line_number);

	*stack = (*stack)->next;
	while (tp->next)
		tp = tp->next;

	tp->next = tmp;
	tmp->next = NULL;
	tmp->prev = NULL;
}
