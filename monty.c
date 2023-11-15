#include "monty.h"

ProgState_t prog_state;

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	prog_state.file = fopen(argv[1], "r");
	if (prog_state.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fexec(&stack);
	fclose(prog_state.file);
	free(prog_state.line);
	free_list(stack);
	exit(EXIT_SUCCESS);
}
