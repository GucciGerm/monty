#include "monty.h"

/**
 * tokenize - Takes line input then breaks into tokens
 * @input: This is the line of input that we are tokenizing
 * @operation: This is argument being passed to our function
 *
 * Return: For 0, Skip the line, 1, Continues to next line
 */

int tokenize(char *input, operation_t *operation)
{
	char deliminators[] = "\t\r\n ";
	char *argvpass;
	char *argument;
	unsigned int inputeval = operation->line_number;

	if (input == NULL)
		return (0);
	argvpass = strtok(input, deliminators);
	if (argvpass == NULL)
		return (0);
	if (argvpass[0] == '#')
		return (0);
	if (strcmp(argvpass, "stack") == 0)
	{
		*operation->mode = 0;
		return (0);
	}
	if (strcmp(argvpass, "queue") == 0)
	{
		*operation->mode = 1;
		return (0);
	}
	if (strcmp(argvpass, "push") == 0)
	{
		argument = strtok(NULL, deliminators);
		if (argument == NULL)
		{
			printf("1:L%d: usage: push integer\n",
			       inputeval);
			exit(EXIT_FAILURE);
		}
		if (checkdigit(argument) != 1)
		{
			printf("2:L%d: usage: push integer\n", inputeval);
			exit(EXIT_FAILURE);
		}
		operation->argument = atoi(argument);
		operation->operation = argvpass;
		return (1);
	}
	operation->operation = argvpass;
	return (1);
}
