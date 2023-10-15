#include "shell.h"

/**
 * rellocat - Adjusts the size of a pointer to twice its original space.
 * @myptr: A pointer to the original array.
 * @mysize: A pointer to the number of elements in the original array
 *
 * Description:
 * This function reallocates the memory for the old array, doubling its size,
 * and returns a pointer to the new array.
 *
 * Return: Pointer to the new size array.
 */
char **rellocat(char **oldptr, size_t *oldsize)
{
	size_t new_size = (*oldsize) * 2 + 10;
	size_t y;

	char **new_ptr = malloc(sizeof(char *) * new_size);

	if (new_ptr == NULL)
	{
		free(oldptr);
		return (NULL);
	}

	for (y = 0; y < (*oldsize); y++)
	{
		new_ptr[y] = oldptr[y];
	}

	for (y = (*oldsize); y < new_size; y++)
	{
		new_ptr[y] = NULL;
	}

	*oldsize = new_size;

	free(oldptr);

	return (new_ptr);
}
