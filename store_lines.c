#include "monty.h"
#include <stdio.h>

/**
 * monty_process - Process Monty bytecode file execute operations manage stack
 * @fd: file descriptor
 * @stack: stack
 * @instructions: array of function pointers
 *
 * Return: void
 */
void monty_process(FILE *fd, stack_t **stack, instruction_t instructions[])
{
	char *file_line = NULL, **tokenized = NULL;
	unsigned int num_lines = 0;

	file_line = malloc(1024);
	if (!file_line)
		exit(EXIT_FAILURE);
	while (fgets(file_line, 1024, fd))
	{
		num_lines++;
		if (is_empty_line(file_line) || is_comment(file_line))
			continue;
		tokenized = tokenize(file_line);
		free(file_line);
		if (!valid_op(tokenized[0], instructions))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num_lines, tokenized[0]);
			free_ptr(tokenized);
			free_stack(stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		insert(tokenized, num_lines, fd);
		free_ptr(tokenized);
		apply_instruction(stack, num_lines, fd, instructions);
		del();
		file_line = malloc(1024);
		if (!file_line)
			exit(EXIT_FAILURE);
	}
	free(file_line);
}

/**
 * apply_instruction - executes instructions in monty bytecode file
 * @stack: stack
 * @line_number: line number where operation is called
 * @fd: file descriptor
 * @instructions: array of function pointers
 *
 * Return: void
 */
void apply_instruction(stack_t **stack, unsigned int line_number,
		FILE *fd, instruction_t instructions[])
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(head.opcode, instructions[i].opcode) == 0)
			(instructions[i].f)(stack, line_number);
		if ((head.err_stat) < 0)
		{
			del();
			free_stack(stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/**
 * is_empty_line - checks if a line is empty
 * @file_line: line read from monty bytecode file
 *
 * Return: true if empty, false if not
 */
bool is_empty_line(char *file_line)
{
	int i = 0;

	if (file_line[i] == '\n')
		return (true);
	while (file_line[i] != '\n')
	{
		if (file_line[i] != ' ' && file_line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

/**
 * free_ptr - frees a pointer to pointer to char
 * @ptr: ptr to be freed
 *
 * Return: void
 */
void free_ptr(char **ptr)
{
	int i = 0;

	if (!ptr)
		return;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

/**
 * is_comment - checks if a line is a comment
 * @file_line: monty bytecode file line
 *
 * Return: True if it's a comment, else false
 */
bool is_comment(char *file_line)
{
	int i = 0;

	while (file_line[i] != '\n' && (file_line[i] == ' ' || file_line[i] == '\t'))
		i++;
	if (file_line[i] != '#')
		return (false);
	return (true);
}
