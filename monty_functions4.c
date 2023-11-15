#include "monty.h"

/**
 * op_pstr - Prints the string starting at the top of the stack,
 * followed by a newline
 * @top: Double pointer to the top of the stack
 * @lineNumber: Current line number in the file
 *
 * Prints the characters as a string from the top of the stack until
 * encountering a non-printable character or reaching the end of the stack.
 * Outputs a newline after printing the string.
 */
void op_pstr(stack_t **top, unsigned int lineNumber)
{
	stack_t *currentNode = *top;
	(void)lineNumber;

	while (currentNode && currentNode->n > 0 && currentNode->n <= 127)
	{
		printf("%c", currentNode->n);
		currentNode = currentNode->next;
	}
	printf("\n");
}
