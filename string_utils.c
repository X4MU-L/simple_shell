#include "main.h"


/*_strlen, _strdup, _strcopy, copy_WO_space, count_words*/
/**
 * _strcopy - copies a str to dest and terminate with a null character
 * @src: string to copy
 * @dest: memory to copy str to
 * Return: returns a dest filled with bytes of str
 */
char *_strcopy(char *dest, const char *src)
{
	size_t i = 0;

	for (; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * copy_WO_space - copies a sets of strings which does not contain spaces
 * @dest: destination to str to
 * @src: string to copy
 * Return: returns the new copy of strings dest
 */
char *copy_WO_space(char *dest, char *src)
{
	size_t i = 0;

	for (; src[i] && src[i] != ' '; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - creates a dynamyic copy of str and returns a pointer to it
 * @str: string to copy and create a memory address to stror it
 * Return: pointer to the copy of str
 */
char *_strdup(const char *str)
{
	size_t i = 0;
	char *ptr = NULL;

	i = _strlen(str);
	ptr = malloc(sizeof(char) * i + 1);

	ptr = _strcopy(ptr, str);

	return (ptr);
}

/**
 * _strlen - gets the lenth of string
 * @str: string to get its length
 * Return: length of str
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * count_words - gets the length a stream char that does not contain space
 * @str: the string to get its first byte without space
 * Return: the length of byte without spaces
 */

size_t count_words(const char *str)
{
	size_t i = 0;

	while (str[i] && str[i] != ' ')
		i++;

	return (i);
}
