#include "monty.h"

/**
 * insert - inserts a new node in a queue of instructions
 * @tokenized: hold the opcode and arguments
 * @line_number: line number on the monty code file
 * @fd: file descriptor
 *
 * Return: void
 */
void insert(char **tokenized, unsigned int line_number, FILE *fd)
{
	head.opcode = malloc(strlen(tokenized[0]) + 1);

	if (!(head.opcode))
		malloc_err(tokenized, fd);

	strcpy(head.opcode, tokenized[0]);
	if (tokenized[1])
	{
		head.args = malloc(strlen(tokenized[1]) + 1);
		if (!(head.args))
		{
			free(head.opcode);
			malloc_err(tokenized, fd);
		}
		strcpy(head.args, tokenized[1]);
	}
	else
		head.args = NULL;
	head.line_number = line_number;
	head.err_stat = 0;
}

/**
 * display - displays the elements of the queue
 *
 * Return: void
 */
void display(void)
{
	if (head.opcode)
		printf("opcode: %s\n", head.opcode);
	if (head.args)
		printf("args: %s\n", head.args);
}

/**
 * del - deletes the only element of the queue
 *
 * Return: void
 */
void del(void)
{
	if (head.opcode)
	{
		free(head.opcode);
		head.opcode = NULL;
	}
	if (head.args)
	{
		free(head.args);
		head.args = NULL;
	}
}

/**
 * malloc_err - does necessary memory deallocation, handles malloc error
 * @ptr: pointer to pointer to char to be freed
 * @fd: file descriptor
 *
 * Return: void
 */
void malloc_err(char **ptr, FILE *fd)
{
	if (ptr)
		free_ptr(ptr);
	if (fd)
		fclose(fd);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
