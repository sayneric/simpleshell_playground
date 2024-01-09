#include "Hell.h"


/**
 * custom_strtok - Custom implementation of strtok function.
 * @str: The string to tokenize.
 * @delimiters: The set of delimiters to use for tokenization.
 *
 * Return: A pointer to the next token or NULL if there are no more tokens.
 */


char *custom_strtok(char *str, const char *delimiters)
{
	static char *nextToken;
	char *tokenStart;

	nextToken = NULL;
	if (str != NULL)
	{
		nextToken = str;
	}
	else
	{
		/* If called with NULL, continue from the last position */
		if (nextToken == NULL)
		{
			return (NULL);
		}
	}
	/* Skip leading delimiters */
	nextToken += strspn(nextToken, delimiters);
	/* If remaining string is empty, return Null */
	if (*nextToken == '\0')
	{
		return (NULL);
	}
	/* Find the start of the token */
	tokenStart = nextToken;

	/* find  the end of token */
	nextToken += strcspn(nextToken, delimiters);
	/* if it is not the end of string, replace the delimiter with '\0'  */
	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}
	else
	{
		/* if it is the end of the string update nextToken to null  */
		nextToken = NULL;
	}
	return (tokenStart);
}
