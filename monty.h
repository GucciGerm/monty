#ifndef MONTYISCOOL
#define MONTYISCOOL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct operation_s - This is a structure of commands
 * @operation: The operation that we are current performing
 * @argument: The Argument that we are performing
 * @mode: Account for whether a stack or a queue
 * @line_number: This is the line to be evaluated
 * @head: This is the beginning of the linked list
 * @tail: This is the end of the linked list
 *
 */
typedef struct operation_s
{
	char *operation;
	int argument;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;

} operation_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(operation_t *operation);
} instruction_t;

/* Prototypes used for functions */

int checkdigit(char *brokentoken);
int main(int argc, char **argv);
void freeyourlist(stack_t **head);
void evaluatein(char *input, stack_t **h, stack_t **t, int *mode,
	       unsigned int inputeval);
void whichfunc(operation_t *operation);
int tokenize(char *input, operation_t **operation);
void pushnode(operation_t *operation);
void pallit(operation_t *operation);
void pint(operation_t *operation);
void pop(operation_t *operation);
void swap(operation_t *operation);
void add(operation_t *operation);
void nop(operation_t *operation);

#endif
