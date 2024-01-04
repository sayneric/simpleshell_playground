#include "Hell.h"
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

int main(int argc, char *argv[])
{
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
		if (argc > 1)
		{
			process_arguments(argc, argv);
			return (0);
		}
		accomplish_task(instruction);
	}
	return (0);
}
