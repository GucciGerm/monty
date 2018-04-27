#include "monty.h"

/**
 * pall - Here we wil print all values from the stack starting at the top (:
 * @operation: This is the specific operation we will be printing
 *
 *
 * Return: VOID IT (:
 */

void pallit(operation_t *operation)
{
	stack_t *h = *operation->head;

	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
