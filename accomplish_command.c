#include "Hell.h"

#define MAX_ARGUMENTS 10


/**
 * tokenize_arguments - Tokenizes a command into arguments.
 * @task: The command to be tokenized.
 * @args: Array to store the tokenized arguments.
 *
 * Description:
 * This function tokenizes the given command using strtok and stores the
 * individual arguments in the provided array. The last element of the array
 * is set to NULL to mark the end of arguments.
 *
 * Parameters:
 * - task: The command to be tokenized.
 * - args: Array to store the tokenized arguments.
 */


void tokenize_arguments(char *task, char *args[])
{
	char *token;
	int arg_index = 0;

	token = strtok(task, " ");
	while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
	{
		args[arg_index++] = token;
		token = strtok(NULL, " ");
	}
	/* Set the last element of the array to NULL */
	args[arg_index] = NULL;
}

/**
 * accomplish_task - Executes a given command.
 * @command: The command to be executed.
 *
 * Description:
 * This function checks if the given command exists in the PATH.
 * If the command is executable, it forks a child process to execute
 * the command using execve. The parent process waits for the child
 * to complete.
 *
 * Parameters:
 * - command: The command to be executed.
 */


void accomplish_task(char *command)
{
	/* check if the command exisits in PATH */
	pid_t pikin_pid;

	if (access(command, X_OK) != 0)
	{
		write(STDERR_FILENO, "command not found\n",
				sizeof("command not found\n") - 1);
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	/* if the command is executable, proceed with fork and execve */
	pikin_pid = fork();
	if (pikin_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pikin_pid == 0)
	{
		/* Child process logic (executing the command) */
		char *args[MAX_ARGUMENTS];
		char *const env_vars[]  = {"PATH=/bin:/usr/bin", NULL };

		tokenize_arguments(command, args);
		if (execve(args[0], args, env_vars) == -1)
		{
			perror("execve");
			free(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent process login (waiting for the child) */
		waitpid(pikin_pid, NULL, 0);
	}
}
