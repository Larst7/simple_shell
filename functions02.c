#include "shell.h"

/**
 * cmprstr - Compares two strings.
 * @mystrcmp1: The first string to be compared in length.
 * @mystrcmp2: The second string to be compared.
 *
 * Return: 0 on success, any other value indicates failure.
 */
int cmprstr(char *mystrcmp1, char *mystrcmp2)
{
	int j = 0;

	while (mystrcmp1[j] && mystrcmp2[j] && mystrcmp1[j] == mystrcmp2[j])
	{
		j++;
	}

	return (mystrcmp1[j] - mystrcmp2[j]);
}

/**
 * strlength - This program outputs the length of a string
 * @strng: String to be measured
 * Return: Outcome
 */
unsigned int strlength(char *strng)
{
	unsigned int length = 0;

	while (strng[length] != '\0')
	{
		length++;
	}

	return (length);
}
