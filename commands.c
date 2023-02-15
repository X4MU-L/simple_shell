#include "main.h"


/**
 * get_cmd - gets the first argument passed to the cmd line
 * @cmd: an array of arguments passed with spaces
 * Return: a dynamic pointer to thecopy of the first argument
 */
char *get_cmd(const char *cmd)
{
	size_t i = 0, len = 0;
	char *token = NULL;

	if (cmd == NULL)
		return (NULL);
/*get the lenght of the first argument*/
	len = count_words(cmd);
	token = malloc(sizeof(char) * len + 1);
	if (token == NULL)
		return (NULL);

	for (; i < len; i++)
		token[i] = cmd[i];
	token[i] = '\0';
	return (token);
}


/**
 * locate_cmd - get the executable PATH of the first command passed in
 * @filename: the first command line argument passed
 * Return: a dynamic pointer to the PATH of the executable or NULL if not found
 */
char *locate_cmd(const char *filename)
{
	char *cmd_path = NULL;
	char *sys_path = NULL;
	char *joined_path = NULL;

	if (file_exits(filename))
		return (_strdup(filename));

	sys_path = _getenv("PATH");
	strtok(sys_path, "=");
	cmd_path = strtok(NULL, ":");
	while (cmd_path)
	{
		joined_path = join_paths('/', cmd_path, filename);
		if (file_exits(joined_path))
			break;
		if (joined_path)
			free(joined_path);
		joined_path = NULL;
		cmd_path = strtok(NULL, ":");
	}
	if (sys_path)
		free(sys_path);
	return (joined_path);

}

/**
 * is_exit - chcks if the first command is "exit"
 * @cmd: command to check
 * Return: 1 if cmd is "exit" else 0
 */
int is_exit(char *cmd)
{
	size_t i = 0, j = 0;
	char *exit = "exit";

	while (cmd[i] == ' ')
		i++;
	while (exit[j] && cmd[i] && cmd[i] == exit[j])
	{
		j++;
		i++;
	}
	if (!exit[j] && (!cmd[i] || cmd[i] == ' '))
		return (1);
	return (0);
}

/**
 * join_paths - joins the a PATH with the first command
 * @sep: a seperator to form the PATH e.g '/'
 * @path: the first path to the executable e.g /bin
 * @filename: name of the command
 * Return: a dynamic pointer to the joined path
 */
char *join_paths(char sep, const char *path, const char *filename)
{
	size_t len = 0, i = 0, j = 0;
	char *full_path = NULL;

	len += _strlen(path);
	len += _strlen(filename);
/*for seperator*/
	len += 1;

	full_path = malloc(sizeof(char) * (len + 1));
	if (full_path == NULL)
		return (NULL);

	for (i = 0; path[i]; i++)
		full_path[i] = path[i];

	full_path[i++] = sep;
	for (j = 0; filename[j]; i++, j++)
		full_path[i] = filename[j];

	full_path[i] = '\0';
	return (full_path);
}

/**
 * create_array - createa pointer to array of arrays of char of size words
 * @cmd_path: path of command to execute
 * @args: remaining args of the command excluding first command
 * @words: size of array of arrays to create
 * Return: pointer to a pointer of chars
 */

char **create_array(int words, const char *cmd_path, const char *args)
{
	size_t len = 0, tmp_len = 0;
	int i = 0;
	char **array = NULL;
	char *str = NULL;

	array = malloc(sizeof(char *) * words);
	if (array == NULL)
		return (NULL);
	i = _strlen(cmd_path);
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
	{
		free(array);
		return (NULL);
	}
	i = 0;
	array[i++] = _strcopy(str, cmd_path);
	while (i < words && args[len])
	{/*move from the spaces*/
		while (args[len] && args[len] == ' ')
			len++;
		if (args[len] != ' ')
		{
			tmp_len = count_words(args + len);
			len += tmp_len;
		}
		str = malloc(sizeof(char) * tmp_len + 1);
		if (str == NULL)
		{
			for (; i >= 0; i--)
				free(array[i]);
			free(array);
			return (NULL);
		}
		array[i] = copy_WO_space(str, (char *) args + (len - tmp_len));
		i++;
	}
	array[i] = NULL;
	return (array);
}
