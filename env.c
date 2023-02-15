#include "main.h"

/**
 * _getenv - returns a copy of the value of environment variable name
 * @name: name of variable to get
 * Return: a pointer to the copy of name is found or NULL if not
 */
char *_getenv(const char *name)
{
	size_t j, i = 0;
	char *env_var = NULL;

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		j = 0;

		while (name[j] && env_var[j] && name[j] == env_var[j])
			j++;
		if (!name[j] && env_var[j] == '=')
			return (_strdup(env_var));
		i++;
	}

	return (NULL);
}
