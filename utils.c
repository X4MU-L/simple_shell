#include "main.h"

/**
 * free_array - frees an array of array allocated on the heap
 * @array: pointer to the array of arrays
 * Return: void
 */
void free_array(char **array)
{
	size_t i = 0;

	for (; array[i]; i++)
		free(array[i]);
	free(array);
}
