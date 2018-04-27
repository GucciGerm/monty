#include "monty.h"

/**
 * pushnode - Here we will push an element on top of the stack
 * @operation: This is the specific operation you'll be accessing
 *
 *
 *
 * Return: VOID it
 */

void pushnode(operation_t *operation)
{
	stack_t **h = operation->head;
	stack_t *newelement = NULL;

	if (h == NULL)
	{
		printf("L%d: usage: push integer\n", operation->line_number);
		exit(EXIT_FAILURE);
	}
	newelement = malloc(sizeof(stack_t));

	if (newelement == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newelement->next = NULL;
	newelement->prev = NULL;
	newelement->n = operation->argument;
	if (*h == NULL)
	{
		*h = newelement;
		return;
	}
	(*h)->prev = newelement;
	newelement->next = *h;
	newelement->prev = NULL;
	*h = newelement;
}
