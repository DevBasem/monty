#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

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
 * struct ProgState_s - Runtime state for Monty program
 * @arg: Value for current command or operation
 * @line: Contents of the current input line
 * @file: Pointer to Monty script file
 *
 * Description: Encapsulates essential state variables for Monty program execution.
 */
typedef struct ProgState_s
{
	char *arg;
	FILE *file;
	char *line;
} ProgState_t;

extern ProgState_t prog_state;

/*exec functions*/
void fexec(stack_t **stack);
void exec_op(char *opcode, stack_t **stack, unsigned int lineNumber);

/*free funtion*/
void free_list(stack_t *top);

/*monty_functions1*/
void op_push(stack_t **top, unsigned int lineNumber);
void op_pall(stack_t **top, unsigned int lineNumber);
void op_pint(stack_t **top, unsigned int lineNumber);
void op_pop(stack_t **top, unsigned int lineNumber);

/*monty_functions2*/
void op_add(stack_t **top, unsigned int lineNumber);
void op_swap(stack_t **top, unsigned int lineNumber);
void op_nop(stack_t **top, unsigned int lineNumber);
void op_sub(stack_t **top, unsigned int lineNumber);

/*monty_functions3*/
void op_div(stack_t **top, unsigned int lineNumber);
void op_mul(stack_t **top, unsigned int lineNumber);
void op_mod(stack_t **top, unsigned int lineNumber);
void op_pchar(stack_t **top, unsigned int lineNumber);

/*monty_functions4*/
void op_pstr(stack_t **top, unsigned int lineNumber);

/*sec_functions*/
int is_number(char *inputStr);
stack_t *add_node(stack_t **top, const int value);

#endif /* monty.h */
