#include "main.h"
/**
 * execute - execute command
 * @command_arg: command to execute
 * Return: 0 on success
 */
int execute(char **command_arg)
{
	char *env[] = {0};
	int exec = 0;
	pid_t my_pid = 0;
	int status = 0;

	my_pid = fork();
	{
		if (my_pid == 0) /*child process*/
		{
			exec = execve(command_arg[0], command_arg, env);
			if (exec == -1)
			{
				if (!command_arg[0])
				{
					exit(EXIT_FAILURE);
				}
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
	}
	return (0);
}
