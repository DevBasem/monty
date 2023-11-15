#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t *stack = NULL;
/**
 * main - Entry point for Monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char opcode[100];
	int value;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;

		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown opcode %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
