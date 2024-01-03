#include "Hell.h"
/**
 * tokenize_arguments - Tokenizes a command into arguments.
 * @task: The command to be tokenized.
 * @args: Array to store the tokenized arguments.
 *
 * Description:
 * This function tokenizes the given command using strtok and stores the
 * individual arguments in the provided array. The last element of the array
 * is set to NULL to mark the end of arguments.
 *
 * Parameters:
 * - task: The command to be tokenized.
 * - args: Array to store the tokenized arguments.
 */


char *tokenize_arguments(char *task)
{
	char *token, *argument[MAX_ARGUMENTS];
	int arg_index = 0;

	token = strtok(task, " ");
	while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
	{
		argument[arg_index++] = token;
		token = strtok(NULL, " ");
	}
	/* Set the last element of the array to NULL */
	argument[arg_index] = NULL;

	return (argument[MAX_ARGUMENTS]);
}
