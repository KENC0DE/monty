#include "monty.h"

/**
 * _div - divides second element by top element
 * @stack: stack
 * @line_number: line in monty bytecode file where div is called
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		head.err_stat = -1;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mul - multiplies second element with top element
 * @stack: stack
 * @line_number: line in monty bytecode file where mul is called
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mod - computes the modulos of the second element by the top element
 * @stack: stack
 * @line_number: line in monty bytecode file where mod is called
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		head.err_stat = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		head.err_stat = -1;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: line in monty bytecode file where pchar is called
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		head.err_stat = -1;
		return;
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		head.err_stat = -1;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line in monty bytecode file where pstr is called
 *
 * Return: void
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *curr;

	curr = *stack;
	while (curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
