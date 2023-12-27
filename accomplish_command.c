#include "Hell.h"

#define MAX_ARGUMENTS 10



/**
 * accomplish_task - Executes a given task in a child process.
 * @task: The task (command) to be executed.
 *
 * Description:
 * This function uses fork() to create a child process. In the child process,
 * it executes the specified task using execve(). The parent process waits
 * for the child to complete its execution.
 *
 * Parameters:
 * - task: The task (command) to be executed.
 *
 * Return:
 * This function does not return a value. It exits with EXIT_SUCCESS on success
 * and EXIT_FAILURE if an error occurs during fork or execve.
 */


void accomplish_task(char *task)
{
	pid_t pikin_pid = fork();

	if (pikin_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pikin_pid == 0)
	{
		/* Child process */

		/* Tokenize the command and arguments */
		char *token, *args[MAX_ARGUMENTS];
		int arg_index = 0;

		token = strtok(task, " ");
		while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
		{
			args[arg_index++] = token;
			token = strtok(NULL, " ");
		}
		/* Set the last element of the array to NULL */
		args[arg_index] = NULL;

		/* Execute the command with arguments using execv */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		wait(NULL);
	}
}
