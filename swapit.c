#include "monty.h"

/**
 * swapit - Here we will swap the very top two elements of the stack
 * @operation: This will be the specific operation being pull
 *
 *
 * Return: Void it
 */

void swapit(operation_t *operation)
{
	stack_t **h = operation->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *third = NULL;

	if (h == NULL)
	{
		printf("L%d: can't swap, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if (*h == NULL)
	{
		printf("L%d: can't swap, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	first = *h;
	second = (*h)->next;
	third = second->next;

	first->next = second->next;
	second->next = first;
	if (third)
		third->prev = first;
	first->prev = second;
	second->prev = NULL;
	*h = second;
}
