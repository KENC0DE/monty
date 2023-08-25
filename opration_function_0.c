#include "monty.h"

/**
 * push - inserts a new node in the stack
 * @stack: stack
 * @line_number: line number in file where push is called
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;


	if (!valid_args(head.opcode, head.args))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		head.err_stat = -1;
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		head.err_stat = -1;
		return;
	}
	if (head.SQ == 1)
	{
		add_node_end(stack, &new_node);
		return;
	}
	new_node->n = atoi(head.args);
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;

	}
}

/**
 * pall - prints all elements of the stack
 * @stack: stack
 * @line_number: line number in file where pall is called
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *curr;

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line where pint is called in the monty bytecode file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		head.err_stat = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack
 * @line_number: line in monty bytecode file where pop is called
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		head.err_stat = -1;
		return;
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * free_stack - frees the stack
 * @stack: stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (!(*stack))
		return;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(*stack);
}
