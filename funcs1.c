#include "monty.h"

/**
  * swap - swaps the top two elements of the stack.
  * @stack: pointer to a pointer to a stack_t structure.
  * @line_number: the current line number in the input file
  */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
}

/**
  * add - adds the top two elements of the stack.
  * @stack: pointer to a pointer to a stack_t structure.
  * @line_number: the current line number in the input file
  */

void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
  * nop -  doesn’t do anything.
  * @stack: pointer to a pointer to a stack_t structure.
  * @line_number: the current line number in the input file
  */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
