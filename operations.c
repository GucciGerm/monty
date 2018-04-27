#include "monty.h"

/**
 * evaluatein - Here we will evaluate the input
 * @input: We will take the input and we will tokenize into chunks (:
 * @hdll: hdll is the head of our double linked list
 * @tdll: tdll is the tail of our double linked list
 * @mode: Accounting for whether it is a stack or a queue
 * @inputeval: This is the number of lines that are inputed and for evaluation
 *
 * Return: VOID IT (:
 */

void evaluatein(char *input, stack_t **hdll, stack_t **tdll, int *mode,
		unsigned int inputeval)
{
	operation_t operation;

	operation.mode = mode;
	operation.line_number = inputeval;
	operation.head = hdll;
	operation.tail = tdll;
	if (tokenize(input, &operation))
		whichfunc(&operation);
}

/**
 * whichfunc - Whichfunc will use an incrementor to move through the operations
 * @operation: the commands that r pass to check if its any of the instructions
 *
 * Return: Void it (:
 */

void whichfunc(operation_t *operation)
{
	int currentop = 0;
	instruction_t funcs[] = {
		{"push", pushnode},
		{"pall", pallit},
		{"pint", pintit},
		{"pop", popit},
		{"swap", swapit},
		{"add", addit},
		{"nop", nopit},
		{NULL, NULL}
	};
	while (!funcs[currentop].opcode)
	{
		if (strcmp(operation->operation, funcs[currentop].opcode) == 0)
		{
			funcs[currentop].f(operation);
			return;
		}
		currentop++;
	}
	printf("L%d: unknown instruction %s\n",
	       operation->line_number, operation->operation);
	exit(EXIT_FAILURE);
}
