#include "monty.h"

/**
 * stack_len - counts the number of elements in a stack
 * @stack: stack
 *
 * Return: number of elements of stack
 */
size_t stack_len(stack_t *stack)
{
	stack_t *curr;
	size_t len = 0;

	if (stack == NULL)
		return (0);
	curr = stack;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line in monty bytecode file where swap is called
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	first = *stack;
	second = (*stack)->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line in monty bytecode file where add is called
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: stack
 * @line_number: line in monty bytecode file where nop is called
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - substracts the top element from the one after it
 * @stack: stack
 * @line_number: line_number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
