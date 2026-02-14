#include "shell.h"

/**
 * execute_cmd - Tokenizes the string and executes the command with args.
 * @line: The raw input string from getline.
 */
void execute_cmd(char *line)
{
	char *args[64];
	char *token;
	int i = 0;
	pid_t child_pid;
	int status;

	token = strtok(line, " \t\r\n");
	while (token != NULL && i < 63)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;

	if (args[0] == NULL)
		return;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
		perror("Fork Error");
	else
		wait(&status);
}