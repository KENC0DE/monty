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
	cmds *new_cmd = malloc(sizeof(cmds)), *curr;

	if (!new_cmd)
		malloc_err(tokenized, fd);
	new_cmd->opcode = malloc(strlen(tokenized[0]) + 1);
	if (!(new_cmd->opcode))
	{
		free(new_cmd);
		malloc_err(tokenized, fd);
	}
	strcpy(new_cmd->opcode, tokenized[0]);
	if (tokenized[1])
	{
		new_cmd->args = malloc(strlen(tokenized[1]) + 1);
		if (!(new_cmd->args))
		{
			free(new_cmd->opcode);
			free(new_cmd);
			malloc_err(tokenized, fd);
		}
		strcpy(new_cmd->args, tokenized[1]);
	}
	else
		new_cmd->args = NULL;
	new_cmd->line_number = line_number;
	new_cmd->err_stat = 0;
	new_cmd->next = NULL;
	if (head == NULL)
	{
		new_cmd->prev = NULL;
		head = new_cmd;
		return;
	}
	curr = head;
	while (curr->next)
		curr = curr->next;
	new_cmd->prev = curr;
	curr->next = new_cmd;
}

/**
 * display - displays the elements of the queue
 *
 * Return: void
 */
void display(void)
{
	cmds *curr;

	if (!head)
		return;
	curr = head;
	while (curr)
	{
		printf("opcode: %s\n", curr->opcode);
		printf("Arguments: %s\n", curr->args);
		printf("Line Number: %d\n", curr->line_number);
		curr = curr->next;
	}
}

/**
 * del - deletes the only element of the queue
 *
 * Return: void
 */
void del(void)
{
	if (head)
	{
		free(head->opcode);
		free(head->args);
		free(head);
		head = NULL;
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
