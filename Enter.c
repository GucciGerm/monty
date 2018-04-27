#include "monty.h"

/**
 * main - Here is where the program reads and evaluates the file
 * @argc: This is the amount of arguments passed
 * @argv: These are the actual arguments being passed
 *
 * Return: You want to return a 0 skips the line, 1 is a success!
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *hdll = NULL;
	stack_t *tdll = NULL;
	int mode = 0;

	unsigned int line_number = 1;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&input, &len, file)) != -1)
	{
		evaluatein(input, &hdll, &tdll, &mode, line_number);
		line_number++;
	}

	fclose(file);
	free(input);
	freeyourlist(&hdll);
	return (EXIT_SUCCESS);
}
