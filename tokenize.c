#include "Hell.h"

/**
 * tokenize_arguments - Tokenize a command into arguments.
 * @task: The command string to be tokenized.
 * @args: An array to store the resulting tokens.
 *
 * This function tokenizes a command string into arguments based on space,
 * tab, newline, carriage return, vertical tab, and form feed delimiters.
 * It handles quotes and escapes within tokens.
 *
 * Return: The first token in the array.
 */


char *tokenize_arguments(const char *task, char *args[])
{
	char *token;
	char *temp_task = strdup(task); /* Non-const temp string */
	int arg_index = 0;
	const char *delimiters;
	bool in_quotes = false;

	delimiters = " \t\r\n\v\f";
	token = custom_strtok(temp_task, delimiters);
	while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
	{
		token = handle_quotes_and_escapes(token, &in_quotes);
		args[arg_index++] = token;
		token = custom_strtok(NULL, delimiters);
	}
	set_last_element_to_null(args, arg_index);
	free(temp_task);
	return (args[0]);
}


/**
 * handle_quotes_and_escapes - Handle quotes and escapes within a token.
 * @token: The token to be processed.
 * @in_quotes: A pointer to a boolean indicating if currently inside quotes.
 *
 * This function processes a token, toggling the in_quotes flag based on
 * quotes and handling escape characters within quotes.
 *
 * Return: The modified token.
 */


char *handle_quotes_and_escapes(char *token, bool *in_quotes)
{
	while (token[0] == '\"' || token[0] == '\\')
	{
		if (token[0] == '\"')
		{
			*in_quotes = !(*in_quotes);
		}
		else if (token[0] == '\\' && *in_quotes)
		{
			/* Skip the escape character within qoutes */
			token = custom_strtok(NULL, " \t\r\n\v\f");
			continue;
		}
		/* Move to the next part of the token */
		token = custom_strtok(NULL, " \t\r\n\v\f");
	}
	return (token);
}


/**
 * set_last_element_to_null - Sets the last element of an array to NULL.
 *
 * @args: The array whose last element needs to be set to NULL.
 * @arg_index: The index of the last valid element in the array.
 *
 * This function sets the last element of the given array to NULL, indicating
 * the end of the array.
 */

void set_last_element_to_null(char *args[], int arg_index)
{
	/* Set the last element of the array to NULL */
	args[arg_index] = NULL;
}
