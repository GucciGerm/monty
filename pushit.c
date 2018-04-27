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
	stack_t *placeholder = NULL;

	if (h == NULL)
	{
		printf("L%d: usuage: push integer\n", operation->line_number);
		exit(EXIT_FAILURE);
	}
	newelement = malloc(sizeof(stack_t));

	if (newelement == NULL)
		exit(EXIT_FAILURE);
	if (*operation->mode == 1)
	{
		newelement->n = operation->argument;
		newelement->next = NULL;
		newelement->prev = NULL;

		if (*h == NULL)
		{
			*h = newelement;
			return;
		}
		placeholder = *h;

		while (placeholder->next != NULL)
			placeholder = placeholder->next;
		placeholder->next = newelement;
		newelement->prev = placeholder;
		return;
	}
	if (*h == NULL)
	{
		newelement->n = operation->argument;
		newelement->next = *h;
		newelement->prev = NULL;
		*h = newelement;
		return;
	}
	(*h)->prev = newelement;
	newelement->n = operation->argument;
	newelement->next = *h;
	newelement->prev = NULL;
	*h = newelement;
}
