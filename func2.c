#include "monty.h"

/**
  * free_stack - frees the memory allocated for the entire stack.
  * @stack: a pointer to a pointer to a stack_t structure
  */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
  * init_stack - initiate a stack.
  * @stack: a pointer to a pointer to a stack_t structure
  *
  * Return: error value number.
  */

int init_stack(stack_t **stack)
{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	stk->n = STACK;
	stk->prev = NULL;
	stk->next = NULL;

	*stack = stk;
	return (EXIT_SUCCESS);
}

/**
  * mode_check - check the mode of operation for a data structure
  * @stack:  It takes a pointer to a stack_t structure.
  *
  * Return: 2 if no condition is met.
  */

int mode_check(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
