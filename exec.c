#include "monty.h"

/**
 * fexec - Execute Monty opcodes from an open file
 * @stack: Pointer to the top of the stack
 *
 * Reads Monty opcodes line by line from the global file, extracting
 * commands and arguments. Skips comments and empty lines. Calls
 * executeOpcode for each valid opcode, tracking execution by line number.
 */
void fexec(stack_t **stack)
{
	char *currentOpcode = NULL;
	size_t lineLength = 0;
	ssize_t bytesRead;
	unsigned int lineNumber = 0;

	while ((bytesRead = getline(&prog_state.line, &lineLength,
					prog_state.file)) != -1)
	{
		lineNumber++;
		currentOpcode = strtok(prog_state.line, " \t\r\n\a");
		prog_state.arg = strtok(NULL, " \n\t");
		if (currentOpcode == NULL || *currentOpcode == '#')
			continue;
		exec_op(currentOpcode, stack, lineNumber);
	}
}

/**
 * exec_op - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer to the top of the stack
 * @lineNumber: line number of the opcode
 *
 * Description:
 * Executes the specified Monty opcode by searching for a matching entry
 * in the instruction set. If found, calls the corresponding function.
 * Exits the program with an error message if the opcode is unknown.
 */
void exec_op(char *opcode, stack_t **stack, unsigned int lineNumber)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"nop", op_nop},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, lineNumber);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
	free_list(*stack);
	fclose(prog_state.file);
	free(prog_state.line);
	exit(EXIT_FAILURE);
}
