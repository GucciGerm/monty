#include "monty.h"

/**
 * popit - Here we will remove the top element from the stack
 * @operation: This is the specific operation we are trying to pop
 *
 * Return: VOID IT
 */

void popit(operation_t *operation)
{
	stack_t **hdll = operation->head;
	stack_t *popnode = NULL;

	if (*hdll == NULL)
	{
		printf("L%d: can't pop an empty stack\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	if (hdll == NULL)
	{
		printf("%d: can't pop an empty stack\n",
		       operation->line_number);
		exit(EXIT_FAILURE);
	}
	popnode = *hdll;
	*hdll = (*hdll)->next;
	free(popnode);
}
