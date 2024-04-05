#include "monty.h"

static instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};
/**
  * execute - tokenize and execute each line of the file.
  * @file: input file.
  */

void execute(FILE *file)
{
	int line_number = 1, i, check = 0;
	char buf[256];
	stack_t *stack = NULL;
	char *opcode;

	while (fgets(buf, sizeof(buf), file))
	{
		buf[strcspn(buf, "\n")] = '\0';
		opcode = strtok(buf, " ");
		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				check = 1;
				break;
			}
		}
		if (!check)
		{
			fprintf(stderr, "L%u: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
}
