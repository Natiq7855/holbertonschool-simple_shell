#include "shell.h"

/**
 * execute_cmd - Tokenizes a line into arguments and executes it.
 * @line: The raw string input from the user.
 *
 * Return: void.
 */
void execute_cmd(char *line)
{
	char *args[1024];
	char *token;
	int i = 0;
	pid_t child_pid;
	int status;

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;
	if (args[0] == NULL)
		return;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}