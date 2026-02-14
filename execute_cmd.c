#include "shell.h"

/**
 * execute_cmd - Forks a process to execute a command.
 * @line: The raw input string from getline.
 */
void execute_cmd(char *line)
{
	pid_t child_pid;
	int status;
	char *args[2];
	char *command;

	command = strtok(line, " \t\r\n");
	
	if (command == NULL)
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