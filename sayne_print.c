#include "Hell.h"

/**
 * sayne_print - Function to print a string to standard output
 * @note: The string to be printed
 *
 * Description: This function writes the given string to the
 * standard output using the write system call.
 * Return : void
 */
void sayne_print(const char *note)
{
	write(STDOUT_FILENO, note, strlen(note));
}
