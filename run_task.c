#include "Hell.h"





/**
 * accomplish_task - Execute specified command if it exists and is executable.
 * @command: The command to execute.
 *
 * This function checks if the specified command is a built-in command.
 * If it is a built-in command, it executes the corresponding function;
 * otherwise, it checks if the command exists and is executable.
 * If the command is found, it is executed; otherwise, an error message is printed.
 */

void accomplish_task(const char *command)
{
	char command_path[MAX_COMMAND_LENGTH];

	/* check if command exists and is executable */
	if (compare_strings(command, "env"))
	{
		/* Handle the 'env' builtin command */
		env_builtin();
	}
	else if (check_command_existence(command, command_path))
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
