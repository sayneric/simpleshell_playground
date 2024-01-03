#include "Hell.h"


/**
 * accomplish_task - Executes a given command.
 * @command: The command to be executed.
 *
 * Description:
 * This function checks if the given command exists in the PATH.
 * If the command is executable, it forks a childi process to execute
 * the command using execve. The parent process waits for the child
 * to complete.
 *
 * Parameters:
 * - command: The command to be executed.
 */


void accomplish_task(char *command)
{
	char *path, *copy_of_path, *tokenize_path;
	char command_path[MAX_COMMAND_LENGTH];
	char *token, *args[MAX_ARGUMENTS];
	int arg_index = 0;
	pid_t pid;

	token = strtok(command, " ");
	while (token != NULL && arg_index < MAX_ARGUMENTS - 1)
	{
		args[arg_index++] = token;
		token = strtok(NULL, " ");
	}
	/* Set the last element of the array to NULL */
	args[arg_index] = NULL;
	
	if (strcmp(args[0], "exit") == 0)
	{
		printf("Goodbye!\n");
		exit(EXIT_SUCCESS);
	}
	/* check if the command exisits in PATH */
	path = getenv("PATH");
	copy_of_path = strdup(path);
	tokenize_path = strtok(copy_of_path, ":");

	while (tokenize_path != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", tokenize_path, args[0]);

		if (access(command_path, X_OK) == 0)
		{
			/* Command found in the current path */
			pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				/* Child process */
				execve(command_path, args, NULL);
				/* If execve fails */
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				/* parent process */
				wait(NULL);
			}
		}

		tokenize_path = strtok(NULL, ":");
	}
	free(copy_of_path);
}
