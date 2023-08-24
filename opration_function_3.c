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
	{
		nop(stack, line_number);
		return;
	}

	if (tp->next)
	{
		*stack = (*stack)->next;
		while (tp->next)
			tp = tp->next;

		(*stack)->prev = NULL;
		tp->next = tmp;
		tmp->next = NULL;
		tmp->prev = tp;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line in monty bytecode file where rotl is called
 *
 * Return: void
 */
void rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *bot, *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	bot = *stack;

	while (bot->next->next)
		bot = bot->next;

	tmp = bot->next;
	bot->next = NULL;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = tmp;
	(*stack)->prev = NULL;
}
