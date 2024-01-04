#include "Hell.h"


#define MAX_COMMAND_LENGTH 100

/**
 * accomplish_task - Execute  specified command if it exists and is executable.
 * @command: The command to execute.
 *
 * This function checks if the specified command exists and is executable.
 * If the command is found, it is executed; otherwise, error message is printed
 * and the program exits with a failure status.
 */

void accomplish_task(const char *command)
{
	char command_path[MAX_COMMAND_LENGTH];

	/* check if command exists and is executable */
	if (check_command_existence(command, command_path))
	{
		/* Execute command */
		execute_command(command_path, command);
	}
	else
	{
		/*If command not found go to next line & wait for input*/
		sayne_print("command not found\n");

	}
}
