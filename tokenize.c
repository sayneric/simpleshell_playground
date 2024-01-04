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


char *tokenize_arguments(const char *task, char *args[])
{
	char *token;
	char *temp_task = strdup(task); /* Non-const temp string */
	int arg_index = 0;

	token = strtok(temp_task, " ");
	while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
	{
		args[arg_index++] = token;
		token = strtok(NULL, " ");
	}
	/* Set the last element of the array to NULL */
	args[arg_index] = NULL;
	free(temp_task); /* free the allocated memory for temp string */
	return (args[0]);
}
