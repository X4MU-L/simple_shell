#include "main.h"

/**
 * main - shell interface
 * Description - This function mimics a shell and while running an
 * infinite loop
 * waits for user inputs and executes the command given by the user.
 * Return: 0 always
 */

int main(void)
{
	char *cmd_array = NULL, *cmd = NULL, *cmd_path = NULL;
	char **args = NULL;
	size_t cmd_size = 0;
	ssize_t n_read = 0;

	while (1)
	{
		printf("#cisfun$ ");/*command prompt*/
		n_read = getline(&cmd_array, &cmd_size, stdin);
		cmd_array[n_read - 1] = 0;/* pop newline char */
		if (is_exit(cmd_array))
			break;
		cmd = get_cmd(cmd_array);
		cmd_path = locate_cmd(cmd);
		if (cmd_path)
		{
			args = getcmd_array(cmd_path, cmd_array, cmd);
			if (args)
			{/*create child process*/
				if (fork() == 0)
				{
					execve(*args, args, environ);
					return (0);
				}
				else
				{
					wait(NULL);
					free(cmd_path);
					free_array(args);
				}
			}
			else
				free(cmd_path);
		}
		else
			dprintf(STDERR_FILENO, "-%s: Command not found\n", cmd);
		free(cmd);
	}
	free(cmd_array);
	return (0);
}


/**
 * getcmd_array - returns and array of commands passed NULL terminated
 * @cmd_path: path to the cmd executable
 * @cmd_args: array of commands passed to the commands line delimited by spaces
 * @cmd: the first line of the arguments
 * Return: array of all arguments passed to the shell NULL terminated
 */
char **getcmd_array(const char *cmd_path, const char *cmd_args,
		    const char *cmd)
{
	size_t i = 0, words = 0, tmp_i = 0;
	char **array = NULL;

	while (cmd[i] && cmd[i] == cmd_args[i])
		i++;
	tmp_i = i;/* save the index of the next argument start or end*/
	words++;
	if (cmd_args[i] && cmd_args[i] == ' ')
	{
		i++;
		tmp_i = i;/*save the start of the second argument*/
		for (; cmd_args[i]; i++)
			if (cmd_args[i] == ' ' && cmd_args[i + 1] != ' ')
				words++;
		words++;
	} /* makes words to equal at least 2 */
	words++;
	array = create_array(words, cmd_path, cmd_args + tmp_i);

	return (array);
}
