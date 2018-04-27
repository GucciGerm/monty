#include "monty.h"

/**
 * checkdigit - Here we will check if the token passed it is a digit
 * @brokentoken: This is the token that was passed to our function
 *
 * Return: return 0 if it is not a digit, return 1 if it is!
 */

int checkdigit(char *brokentoken)
{
	if (brokentoken == NULL)
		return (0);
	if (*brokentoken == '-')
		brokentoken++;
	while (*brokentoken != '\0')
	{
		if (isdigit(*brokentoken) == 0)
			return (0);
		brokentoken++;
	}
	brokentoken++;
	return (1); /* Yay it is a digit :3 */
}
