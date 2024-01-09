#include "Hell.h"



/**
 * read_input - Reads input from standard input into a buffer.
 *
 * @buffer_size: Pointer to the size of the buffer.
 * @buffer_pos: Pointer to the current position in the buffer.
 *
 * Return: On success, a pointer to the buffer containing the input.
 *         On failure or end of file, returns NULL.
 */

char *read_input(size_t *buffer_size, size_t *buffer_pos)
{
	static char *buffer;
	ssize_t bytes_read;

	buffer = NULL;
	if (*buffer_pos >= *buffer_size)
	{
		bytes_read = read(STDIN_FILENO, buffer, INITIAL_BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		*buffer_size = bytes_read + 1;
		buffer = (char *)realloc(buffer, *buffer_size);
		if (!buffer)
		{
			return (NULL);
		}
		buffer[*buffer_size - 1] = '\0';
		buffer_pos = 0;
	}
	return (buffer);
}


/**
 * custom_getline - Read a line from standard input.
 *
 * This function reads a line from standard input, dynamically allocating
 * memory for the line. The buffer size is adjusted as needed.
 *
 * Return: On success, a pointer to the allocated memory containing the line.
 *         On failure or end of file, returns NULL.
 */
char *custom_getline(void)
{
	static size_t buffer_size;
	size_t buffer_pos, i, start, length;
	char *line, *buffer;

	buffer = NULL;
	buffer_size = 0;
	buffer_pos = 0;
	while (1)
	{
		buffer = read_input(&buffer_size, &buffer_pos);

		if (!buffer)
		{
			return (NULL);
		}

		start = buffer_pos;
		while (buffer_pos < buffer_size && buffer[buffer_pos] != '\n')
		{
			buffer_pos++;
		}
		length = buffer_pos - start;
		line = (char *)malloc(length + 1);
		if (!line)
		{
			return (NULL);
		}
		for (i = 0; i < length; i++)
		{
			line[i] = buffer[start + i];
		}
		line[length] = '\0';
		if (buffer_pos < buffer_size && buffer[buffer_pos] == '\n')
		{
			buffer++;
			return (line);
		}
	}
}
