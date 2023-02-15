#include "main.h"

/**
 * file_exits - checks if a file
 * @path: absolute path of file to check
 * Return: 1 if file is else 0
 */
int file_exits(const char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) == 0)
		return (1);
	return (0);
}

