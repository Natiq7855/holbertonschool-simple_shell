#include "shell.h"

/**
 * execute_cmd - Forks a process to execute a command.
 * @command: The full path to the executable.
 *
 * Return: Void.
 */
void execute_cmd(char *command)
{
	pid_t child_pid;
	int status;
	char *args[2];

	if (command[0] == '\0')
		return;

	args[0] = command;
	args[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}