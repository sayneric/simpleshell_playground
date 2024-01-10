#include "Hell.h"




/**
 * env_builtin - Print the current environment.
 *
 * Description:
 * This function prints the current environment variables to standard output.
 */


void env_builtin(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		sayne_print(*env_var);
		sayne_print("\n");
		env_var++;
	}
}

/**
 * main - Entry point of the simple shell program.
 *
 * Description:
 * This function serves as the entry point for the simple shell program.
 * It runs an infinite loop where it displays a prompt, interprets the
 * user-entered command, and accomplishes the specified task.
 *
 * Return:
 * The function returns 0 to indicate successful execution.
 */

int main(void)
{
	char *argv[MAX_ARGUMENTS];
	char instruction[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		interpret_command(instruction, sizeof(instruction));
		if (compare_strings(instruction, "exit"))
		{
			sayne_print("Exiting the program.\n");
			break;
		}
		accomplish_task(instruction, argv);
	}
	return (0);
}
