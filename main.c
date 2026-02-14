#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, or the exit status of the last command.
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)ac;

	while (1)
	{
		/* 1. Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		/* 2. Read input from user */
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* 3. Handle the input (Placeholder for parsing and execution) */
		handle_input(line, av[0]);
	}

	free(line);
	return (0);
}
