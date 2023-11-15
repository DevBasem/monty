#include "monty.h"

/**
 * add_node - Adds a new node with the given value at the beginning of a stack_t list
 * @top: Pointer to the top of the stack
 * @value: Value to be added to the new node
 * Return: Pointer to the newly added node, or NULL on failure
 */
stack_t *add_node(stack_t **top, const int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*top);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*top)
	{
		new_node->next = *top;
		(*top)->prev = new_node;
	}
	else
		new_node->next = NULL;

	*top = new_node;
	return new_node;
}

/**
 * is_number - Checks if a string represents a valid integer
 * @inputStr: String to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_number(char *inputStr)
{
	if (inputStr == NULL || *inputStr == '\0')
		return (0);

	if (*inputStr == '-' || *inputStr == '+')
		inputStr++;

	while (*inputStr != '\0')
	{
		if (*inputStr < '0' || *inputStr > '9')
			return (0);

		inputStr++;
	}

	return (1);
}
