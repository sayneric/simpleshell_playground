#include "Hell.h"

/**
 * execute_command - Execute a command in a child process.
 * @command_path: The full path to the command to be executed.
 * @command: The command to be executed.
 *
 * This function forks a child process to execute the specified command.
 * Child process uses execve to replace its image with the specified command.
 * The parent process waits for the child process to complete.
 */

void execute_command(const char *command_path, const char *command)
{
	pid_t pikin_pid;

	pikin_pid = fork();
	if (pikin_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pikin_pid == 0)
	{
		/* Child process logic */
		char *args[MAX_ARGUMENTS];

		tokenize_arguments(command, args);
		if (execve(command_path, args, environ) == -1)
		{
			perror("exexve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process logic(waiting for the child) */
		waitpid(pikin_pid, NULL, 0);
	}
}
