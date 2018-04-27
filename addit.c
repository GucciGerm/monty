#include "monty.h"

/**
 * addit - Here we will add the very two top elements of my stack
 * @operation: This is the specific operation we are pulling
 *
 * Return: Void it
 */

void addit(operation_t *operation)
{
	stack_t **h = operation->head;
	stack_t *firstelement = NULL;
	stack_t *secondelement = NULL;
	int total = 0;

	if (operation == NULL)
	{
		printf("L%d: can't add, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if (h == NULL)
	{
		printf("L%d: can't add, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if (*h == NULL)
	{
		printf("L%d: can't add, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	firstelement = *h;
	secondelement = (*h)->next;

	total = firstelement->n + secondelement->n;
	secondelement->n = total;

	popit(operation);
}
