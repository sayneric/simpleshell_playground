#include "Hell.h"


/**
 * process_arguments - Process and interpret command line arguments.
 * @argc: The number of command line arguments.
 * @argv: An array of strings representing the command line arguments.
 *
 * This function prints and interprets the command line arguments.
 * It assumes the presence of a function sayne_print for printing.
 */


void process_arguments(int argc, char *argv[])
{
	int i;

	sayne_print("command line arguments:\n");
	for (i = 1; i < argc; ++i)
	{
		sayne_print(argv[i]);
		sayne_print("\n");
	}
}
