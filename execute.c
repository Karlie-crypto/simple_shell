#include "commands.h"
#include "general.h"
#include "memory.h"

/**
 * execute - Execute a command in other process
 *
 * @command: Command to execute
 * @arguments: Arguments of the @command
 * @info: General info about the shell
 * @buff: Line readed
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}


/**
 * current_directory - Execute the command if the order require
 *
 * @cmd: Command to execute
 * @arguments: Arguments of the @cmd
 * @buff: Line readed
 * @info: General info about the shell
 *
 * Return: Status of the operations
 **/
int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}

