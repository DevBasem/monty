#include "monty.h"

/**
 * free_stack - Free the memory allocated for the stack
 * @stack: Double pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
