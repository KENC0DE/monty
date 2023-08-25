#include "monty.h"

/**
 * stack_f - switches the mode to stack
 * @stack: stack
 * @line_number: the line where stack is called
 *
 * Return: NULL
 */
void stack_f(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		head.SQ = 0;
		return;
	}

	if (head.SQ == 0)
		return;
	head.SQ = 0;
}

/**
 * queue_f - switches the mode to queue
 * @stack: stack
 * @line_number: the line where queue is called
 *
 * Return: NULL
 */
void queue_f(stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		head.SQ = 1;
		return;
	}

	if (head.SQ == 1)
		return;
	head.SQ = 1;
}
