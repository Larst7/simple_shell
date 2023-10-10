#include "shell.h"

/**
 * rellocat - Reallocates a pointer to double the space.
 * @myptr: Pointer to the old array.
 * @mysize: Pointer to number of elements in the old array.
 *
 * Description:
 * This function reallocates the memory for the old array, doubling its size,
 * and returns a pointer to the new array.
 *
 * Return: Pointer to the new size array.
 */
char **rellocat(char **myptr, size_t *mysize)
{
	size_t new_size = (*mysize) * 2 + 10;
	size_t y;

	char **new_ptr = malloc(sizeof(char *) * new_size);

	if (new_ptr == NULL)
	{
		free(myptr);
		return (NULL);
	}

	for (y = 0; y < (*mysize); y++)
	{
		new_ptr[y] = myptr[y];
	}

	for (y = (*mysize); y < new_size; y++)
	{
		new_ptr[y] = NULL;
	}

	*mysize = new_size;

	free(myptr);

	return (new_ptr);
}
