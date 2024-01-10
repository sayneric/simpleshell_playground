#include "Hell.h"





/**
 * accomplish_task - Execute specified command if it exists and is executable.
 * @command: The command to execute.
 * @argv: character array
 *
 * This function checks if the specified command is a built-in command.
 * If it is a built-in command, it executes the corresponding function;
 * otherwise, it checks if the command exists and is executable.
 * If the command is found, it is executed; otherwise, an error message is printed.
 */

void accomplish_task(char *command, char *argv[])
{
	/* check if command exists and is executable */
	if (compare_strings(command, "env"))
	{
		/* Handle the 'env' builtin command */
		env_builtin();
	}
	else
	{
		/* Execute command */
		execute_command(command, argv);
	}

}
