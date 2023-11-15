#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * If the stack has less than two elements, prints an error message and exits.
 * Adds the top two elements of the stack and removes the top element.
 * Exits on memory allocation failure.
 */
void op_add(stack_t **top, unsigned int lineNumber)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		free(prog_state.line);
		free_list(*top);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n += (*top)->n;
	op_pop(top, lineNumber);
}

/**
 * op_swap - Swaps the top two elements of the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * Swaps the positions of the top two elements in the stack.
 * Exits with an error message if the stack has fewer than two elements.
 */
void op_swap(stack_t **top, unsigned int lineNumber)
{
	stack_t *secondNode;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		free(prog_state.line);
		free_list(*top);
		exit(EXIT_FAILURE);
	}

	secondNode = (*top)->next;
	(*top)->next = secondNode->next;

	if (secondNode->next)
		secondNode->next->prev = *top;

	secondNode->prev = NULL;
	secondNode->next = *top;
	(*top)->prev = secondNode;
	*top = secondNode;
}

/**
 * op_nop - Does nothing
 * @top: Pointer to the top of the stack
 * @lineNumber: Line number of the opcode
 *
 * This opcode performs no operation and is used as a placeholder.
 */
void op_nop(stack_t **top, unsigned int lineNumber)
{
	(void)top;
	(void)lineNumber;
}

/**
 * op_sub - Subtracts the top element from the second top element of the stack
 * @top: Double pointer to the head of the stack
 * @lineNumber: Current line number in the file
 *
 * If the stack has fewer than two elements, exits with an error message.
 * Subtracts the top element from the second top element and updates the stack.
 */
void op_sub(stack_t **top, unsigned int lineNumber)
{
	int result;
	stack_t *currentNode;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	currentNode = *top;
	result = currentNode->next->n - currentNode->n;
	currentNode->next->n = result;
	*top = currentNode->next;
	free(currentNode);
}
