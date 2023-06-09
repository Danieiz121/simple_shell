#include "shell.h"

/**
 * env - prints current environment
 * @tokenized_cmnd: command entered
 * Return: empty
 */
void env(char **tokenized_cmndi __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - exits the shell
 * @tokenized_cmnd: command entered
 * Return: empty
 */
void quit(char **tokenized_cmnd)
{
	int num_token = 0,arg;

	for (; tokenized_cmnd[num_token] != NULL; num_token++)
	{
		;
	}
	if (num_token == 1)
	{
		free(tokenized_cmnd);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_cmnd[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number:", STDERR_FILENO);
			print(tokenized_cmnd[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_cmnd);
			free(commands);
			exit(arg);
		}
	}
	else
	{
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
	}
}
