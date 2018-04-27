#include "monty.h"

/**
 * pintit - Here we will print the first value
 * @operation: This is the specific operation we'll be using
 *
 *
 * Return: VOID IT (:
 */


void pintit(operation_t *operation)
{
	stack_t *h = *operation->head;

	if (h == NULL)
	{
		printf("L%d: can't pint, stack empty\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
