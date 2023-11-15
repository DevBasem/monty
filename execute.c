#include "monty.h"

/**
 * execute - reads instructions from a file and executes them
 * @filename: name of the file containing instructions
 */
void execute(const char *filename)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack;
	FILE *file = fopen(filename, "r");
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = strtok(line, " \n");
		int found = 0;
		int j;

		line_number++;
		if (!opcode)
			continue;

		for (j = 0; instructions[j].opcode; j++)
		{
			if (strcmp(opcode, instructions[j].opcode) == 0)
			{
				instructions[j].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
}
