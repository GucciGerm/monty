#include "monty.h"

/**
 * freeyourlist - Here we will free the blocks taking space on the stack
 * @head: Is the head of your stack
 *
 */

void freeyourlist(stack_t **head)
{
	stack_t *element = NULL;
	stack_t *placeholder = NULL;

	if (*head)
	{
		element = *head;
		*head = NULL;

		while (element->next)
		{
			placeholder = element;
			element = element->next;
			free(placeholder);
		}
		free(element);
	}
}
