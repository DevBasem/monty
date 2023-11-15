#include "monty.h"

/**
 * op_div - Divides the second top element by the top element of the stack
 * @top: Double pointer to the head of the stack
 * @lineNumber: Current line number in the file
 *
 * Exits with an error message if the stack has fewer than two elements
 * or if the top element is zero. Divides the second top element by the top
 * element and updates the stack.
 */
void op_div(stack_t **top, unsigned int lineNumber)
{
	int result;
	stack_t *currentNode;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	currentNode = *top;
	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	result = currentNode->next->n / currentNode->n;
	currentNode->next->n = result;
	*top = currentNode->next;
	free(currentNode);
}

/**
 * op_mul - Multiplies the second top element with the top element of the stack
 * @top: Double pointer to the head of the stack
 * @lineNumber: Current line number in the file
 *
 * Exits with an error message if the stack has fewer than two elements.
 * Multiplies the second top element by the top element and updates the stack.
 */
void op_mul(stack_t **top, unsigned int lineNumber)
{
	int multiplicationResult;
	stack_t *currentNode;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	currentNode = *top;
	multiplicationResult = currentNode->next->n * currentNode->n;
	currentNode->next->n = multiplicationResult;
	*top = currentNode->next;
	free(currentNode);
}

/**
 * op_mod - Computes the modulus of the second top element with the top element
 * @top: Pointer to the top of the stack
 * @lineNumber: Current line number in the file
 *
 * Exits with an error message if the stack has fewer than two elements
 * or if the top element is zero. Computes the modulus and updates the stack.
 */
void op_mod(stack_t **top, unsigned int lineNumber)
{
	int divisor, dividend;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	divisor = (*top)->n;
	dividend = (*top)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n = dividend % divisor;
	op_pop(top, lineNumber);
}

/**
 * op_pchar - Prints the character at the top of the stack
 * @top: Pointer to the top of the stack
 * @lineNumber: Current line number in the file
 *
 * Exits with an error message if the stack is empty or if the value
 * at the top of the stack is out of the ASCII range (0-127). Prints the
 * character at the top of the stack.
 */
void op_pchar(stack_t **top, unsigned int lineNumber)
{
	int characterValue;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	characterValue = (*top)->n;
	if (characterValue < 0 || characterValue > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", characterValue);
}
