#include "monty.h"

/**
  * check_int - checks whether a given string represents a valid integer.
  * @str: pointer to string array.
  *
  * Return: True if string or false else.
  */

bool check_int(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (false);
	}

	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			printf("%s\n", str);
			return (false);
		}
		str++;
	}
	return (true);
}

/**
  * push - push integer onto a stack.
  * @stack: doublr pointer to stack.
  * @line_number: representthe current line number in the input file
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int val;
	char *arg = strtok(NULL, DELIM);

	if (arg == NULL || !check_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val  = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
  * pall - print all the values in the stack.
  * @stack: doublr pointer to stack
  * @line_number: representthe current line number in the input file
  */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void) line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
  *  pint - print the value of the top element of the stack.
  * @stack: doublr pointer to stack
  * @line_number: representthe current line number in the input file
  */

void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}

/**
  * pop - remove the top element of the stack.
  * @stack: doublr pointer to stack
  * @line_number: representthe current line number in the input file
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
