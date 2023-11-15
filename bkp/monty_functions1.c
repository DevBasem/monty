#include "monty.h"

/**
 * op_push - Pushes an integer onto the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Current line number in the Monty file
 *
 * If the argument is not a valid integer, prints an error message and exits.
 * Pushes the integer onto the stack using the add_node function.
 * Exits on memory allocation failure.
 */
void op_push(stack_t **top, unsigned int lineNumber)
{
	int value;

	if (!prog_state.arg || !is_number(prog_state.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		free_list(*top);
		fclose(prog_state.file);
		free(prog_state.line);
		exit(EXIT_FAILURE);
	}

	value = atoi(prog_state.arg);
	if (!add_node(top, value))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*top);
		fclose(prog_state.file);
		free(prog_state.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pall - Prints all values on the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * Prints each integer value on the stack, starting from the top.
 * Ignores the line number parameter.
 */
void op_pall(stack_t **top, unsigned int lineNumber)
{
	stack_t *currentNode = *top;

	while (currentNode)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next;
	}
	(void)lineNumber;
}

/**
 * op_pint - Prints the value at the top of the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * Prints the integer value at the top of the stack.
 * Exits with an error message if the stack is empty.
 */
void op_pint(stack_t **top, unsigned int lineNumber)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNumber);
		free(prog_state.line);
		free_list(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}

/**
 * op_pop - Removes the top element from the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * Removes the top element from the stack and updates the stack pointer.
 * Exits with an error message if the stack is empty.
 */
void op_pop(stack_t **top, unsigned int lineNumber)
{
	stack_t *nextNode;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
		free(prog_state.line);
		free_list(*top);
		exit(EXIT_FAILURE);
	}

	nextNode = (*top)->next;
	free(*top);
	*top = nextNode;

	if (*top)
		(*top)->prev = NULL;
}
