#include "Hell.h"

/**
 * _strchr - checks string for a particular character
 * @str: string to check
 * @c: character
 * Return: Return pointer to the found character
 */

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * _strlen - measures the length of a string
 * @str: string
 * Return: Return the number of characters in str
 */

int _strlen(const char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strcpy - copy string from source to destination
 * @dest: destination
 * @src: source
 * Return: Return pointer to the beginning of the destination string
 */

char *_strcpy(char *dest, const char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (start);
}

/**
 * _strconcat - concatenate strings
 * @prefix:prefix
 * @suffix: suffix
 * Return: Return pointer to the new string
 */

char *_strconcat(const char *prefix, const char *suffix)
{
	int prefix_len = _strlen(prefix);
	int suffix_len = _strlen(suffix);
	char *result = malloc(prefix_len + suffix_len + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	_strcpy(result, prefix);  /*  Copy prefix to result */
	_strcpy(result + prefix_len, suffix);
	return (result);
}

/**
 * execute_command - Execute a command in a child process.
 * @argv: The full path to the command to be executed.
 * @command: The command to be executed.
 * This function forks a child process to execute the specified command.
 * Child process uses execve to replace its image with the specified command.
 * The parent process waits for the child process to complete.
 */

void execute_command(char *command, char *argv[])
{
	int i = 0;
	pid_t pikin_pid = fork();

	if (pikin_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pikin_pid == 0)
	{
		argv[i++] = strtok(command, " ");
		while ((argv[i++] = strtok(NULL, " ")) != NULL)
		argv[i - 1] = NULL;  /* Add NULL terminator */
		if (_strchr(argv[0], '/') != NULL)
		{
			if (access(command, X_OK) == 0)
			{
				execve(argv[0], argv, NULL);
			}
		}
		else
		{
			char *full_path = _strcont("/bin/", argv[0]);

			if (access(full_path, X_OK) == 0)
			{  /* Check if command exists in /bin/ */
				execve(full_path, argv, NULL);
			}
			else
			{
				sayne_print("%s: command not found\n", argv[0]);
			}
		}
		perror("execve");  /* Reached only if execve fails */
		exit(1);
	}
	else
	{
		waitpid(pikin_pid, NULL, 0);
	}
}
