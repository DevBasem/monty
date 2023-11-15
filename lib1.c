#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @value: Value to push onto the stack
 * @line_number: Line number in the file
 */
void push(stack_t **stack, int value, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
