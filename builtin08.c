#include "shell.h"

/**
 * _atoi - Transform a string into an integer.
 * @mystr: String to convert.
 *
 * Description:
 * This function attempts to convert the input string into an integer.
 * If successful, it returns the integer value. If an error occurs during
 * conversion, it returns -1.
 *
 * Return: The integer value, or -1 if an error occurs.
 */
int _atoi(char *mystr)
{
	unsigned int a, a_digit;
	int num = 0, new_test;

	new_test = INT_MAX;
	for (a_digit = 0; new_test != 0; a_digit++)
	{
		new_test /= 10;
	}
	for (a = 0; mystr[a] != '\0' && a < a_digit; a++)
	{
		num *= 10;
		if (mystr[a] < '0' || mystr[a] > '9')
		{
			return (-1);
		}
		if ((a == a_digit - 1) && (mystr[a] - '0' > INT_MAX % 10))
		{
			return (-1);
		}
		num += mystr[a] - '0';
		if ((a == a_digit - 2) && (mystr[a + 1] != '\0') && (num > INT_MAX / 10))
		{
			return (-1);
		}
	}
	if (a > a_digit)
	{
		return (-1);
	}
	return (num);
}
