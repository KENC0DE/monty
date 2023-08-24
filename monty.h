#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct commands - doubly linked holding necessary operation information
 * @opcode: operation code
 * @args: operation arguments
 * @line_number: line number on file where operation is
 * @err_stat: holds the error status when an error is triggered
 * @prev: points to the previous element
 * @next: points to the next element
 *
 * Description: a queue that holds the necessary information to run monty
 * bytecode operations
 */
typedef struct commands
{
	char *opcode;
	char *args;
	unsigned int line_number;
	int err_stat;
	struct commands *next;
	struct commands *prev;
} cmds;

extern cmds *head;

/* Queue functions */
void insert(char **tokenized, unsigned int line_number, FILE *fd);
void display(void);
void del(void);

/* Stack functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl_f(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* count stack elements */
size_t stack_len(stack_t *stack);

/* monty bytecode file processing */
void monty_process(FILE *fd, stack_t **stack, instruction_t instructions[]);
void apply_instruction(stack_t **stack, unsigned int line_number,
		FILE *fd, instruction_t instructions[]);

/* line validation */
bool valid_op(char *op, instruction_t instructions[]);
bool valid_args(char *op, char *args);

/* memory deallocation */
void free_ptr(char **ptr);
void malloc_err(char **ptr, FILE *fd);
void free_stack(stack_t **stack);

/* tokenize line read from file */
char **tokenize(char *file_line);

/* helpers */
bool is_empty_line(char *file_line);
bool is_comment(char *file_line);
#endif
