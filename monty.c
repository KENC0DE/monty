#include "monty.h"

void unused(void);
cmds head = {NULL, NULL, 0, 0, 0};

/**
 * main - execution point of monty interpreter
 * @ac: argument count
 * @av: argument variables
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *fd;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},	{"pall", pall},
		{"pint", pint},	{"pop", pop},
		{"swap", swap},	{"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl_f},
		{"rotr", rotr}, {"queue", queue_f},
		{"stack", stack_f}, {NULL, NULL}
	};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	monty_process(fd, &stack, instructions);
	free_stack(&stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
