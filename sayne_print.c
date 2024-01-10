#include "Hell.h"

/**
 * sayne_print - Function to print a string to standard output
 * @format: The string to be printed
 *
 * Description: This function writes the given string to the
 * standard output using the write system call.
 * Return : void
 */
void sayne_print(const char *format, ...)
{
	char ch;
	const char *str_arg;
	const char *ptr;
	va_list args;

	va_start(args, format);
	ptr = format;
	while (*ptr != '\0')
	{
		if (*ptr == '%' && *(ptr + 1) == 's')
		{
			str_arg = va_arg(args, const char *);
			write(STDOUT_FILENO, str_arg, strlen(str_arg));
			ptr += 2;
		}
		else
		{
			ch = *ptr;
			write(STDOUT_FILENO, &ch, 1);
			ptr++;
		}
	}
	va_end(args);
}
