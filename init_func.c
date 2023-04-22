#include "shell.h"

/**
 * init - executes everything in the shell
 * @curr_cmnd: current token
 * @typed_cmnd: parsed token
 * Return: empty
 */
void init(char **curr_cmnd, int typed_cmnd)
{
	pid_t PID;

	if (typed_cmnd == EXTERNAL_COMMAND || typed_cmnd == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
		{
			execute_command(curr_cmnd, typed_cmnd);
		}
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
	{
		execute_command(curr_cmnd, typed_cmnd);
	}
}
