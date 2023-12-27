#include "Hell.h"


/**
 * interpret_command - Reads and interprets a command from standard input.
 * @instruction: Buffer to store the entered command.
 * @size: Size of the buffer.
 *
 * Description:
 * This function reads a command from the standard input using fgets.
 * It checks for errors during the input process and handles them accordingly.
 * The newline character at the end of the command is replaced with
 * a null terminator.
 *
 * If an error occurs while reading input or reaching the end of the file,
 * an appropriate message is printed, and the program exits with the
 * corresponding status.
 *
 * Parameters:
 * - instruction: The buffer to store the entered command.
 * - size: The size of the buffer.
 */


void interpret_command(char *instruction, size_t size)
{
	if (fgets(instruction, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			sayne_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			sayne_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	instruction[strcspn(instruction, "\n")] = '\0';
}
