#include "shell.h"

/**
 * my_latoi - Convert a string into an integer.
 * @mystr: String to convert.
 *
 * Description:
 * This function attempts to convert the input string into an integer.
 * If successful, it returns the integer value. If an error occurs during
 * conversion, it returns -1.
 *
 * Return: The integer value, or -1 if an error occurs.
 */
int my_latoi(char *mystr)
{
	unsigned int a, digit;
	int number = 0, n_test;

	n_test = INT_MAX;
	for (digit = 0; n_test != 0; digit++)
	{
		n_test /= 10;
	}
	for (a = 0; mystr[a] != '\0' && a < digit; a++)
	{
		number *= 10;
		if (mystr[a] < '0' || mystr[a] > '9')
		{
			return (-1);
		}
		if ((a == digit - 1) && (mystr[a] - '0' > INT_MAX % 10))
		{
			return (-1);
		}
		number += mystr[a] - '0';
		if ((a == digit - 2) && (mystr[a + 1] != '\0') && (number > INT_MAX / 10))
		{
			return (-1);
		}
	}
	if (a > digit)
	{
		return (-1);
	}
	return (number);
}
