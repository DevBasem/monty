#include "monty.h"

/**
 * free_list - Frees a stack_t linked list
 * @top: Pointer to the top of the stack
 *
 * Description:
 * Frees the memory allocated for a stack_t linked list starting from
 * the specified top node. Continues freeing each node until the end
 * of the list is reached.
 */
void free_list(stack_t *top)
{
	stack_t *current_node;

	while (top != NULL)
	{
		current_node = top;
		top = top->next;
		free(current_node);
	}
}
