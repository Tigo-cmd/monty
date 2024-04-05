#include "monty.h"

/**
  * main - entry point to monty interpretor.
  * @argc: count of passed arguments.
  * @argv: pointer to list of arguements.
  *
  * Return: EXIT_FAILURE on fail or EXIT_SUCCESS on success.
  */

int main(int argc, char *argv[])
{
	FILE *file;
	char *newfile;

	(void) argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	newfile = argv[1];
	file = fopen(newfile, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", newfile);
		return (EXIT_FAILURE);
	}
	execute(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
