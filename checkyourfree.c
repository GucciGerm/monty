#include "monty.h"

/**
 * freeyourlist - Here we will free the blocks taking space on the stack
 * @head: Is the head of your stack
 *
 */

void freeyourlist(stack_t **head)
{
	stack_t *element = NULL;

	if (!*head)
		return;
	while (*head != NULL)
	{
		element = *head;
		*head = (*head)->next;
		free(element);
	}
}
