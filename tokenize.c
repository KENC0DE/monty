#include "monty.h"

/**
 * tokenize - splits and stores line read from monty bytecode file
 * @file_line: line read from file
 *
 * Return: tokenized line
 */
char **tokenize(char *file_line)
{
	char *line_cpy, *token, **new_line = NULL;
	size_t i = 0;

	new_line = malloc(4 * sizeof(char *));
	line_cpy = malloc(strlen(file_line) + 1);
	strcpy(line_cpy, file_line);
	token = strtok(line_cpy, " \t\n");
	while (i < 2 && token != NULL)
	{
		new_line[i] = malloc(strlen(token) + 1);
		strcpy(new_line[i], token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	new_line[i] = NULL;
	free(line_cpy);
	return (new_line);
}

/**
 * valid_op - checks if the opcode is valid
 * @op: opcode
 * @instructions: array of function pointers
 *
 * Return: true if valid, else false
 */
bool valid_op(char *op, instruction_t instructions[])
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
			return (true);
		i++;
	}
	return (false);
}

/**
 * valid_args - checks if the operation arguments are valid
 * @op: opcode
 * @args: string containing the arguments
 *
 * Return: true if valid, else false
 */
bool valid_args(char *op, char *args)
{
	size_t i;

	if (strncmp(op, "push", strlen("push")) == 0)
	{
		if (args)
		{
			for (i = 0; i < strlen(args); i++)
			{
				if (i == 0 && args[0] == '-')
					continue;
				if (!isdigit(args[i]))
					return (false);
			}
			return (true);
		}
		return (false);
	}
	return (true);
}
