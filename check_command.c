#include "Hell.h"


/**
 * check_command_existence - Check if a command exists in the PATH
 * & is executable.
 * @command: The command to check for existence.
 * @command_path: A buffer to store the full path of the command if it exists.
 *
 * Return: 1 if the command exists and is executable, 0 otherwise.
 */




int check_command_existence(const char *command, char *command_path)
{
	char *path = getenv("PATH");
	char *copy_of_path = strdup(path);
	char *tokenize_path = strtok(copy_of_path, ":");

	while (tokenize_path != NULL)
	{
		strcpy(command_path, tokenize_path);
		strcat(command_path, "/");
		strcat(command_path, command);

		if (access(command_path, F_OK | X_OK) == 0)
		{
			/* Command exists and s executable */
			return (1);
		}
		tokenize_path = strtok(NULL, ":");
	}
	return (0);
}
