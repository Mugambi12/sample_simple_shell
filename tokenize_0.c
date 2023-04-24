#include "shell.h"

/**
 * strtow - splits a string into words, ignoring repeat delimiters.
 * @str: the input string.
 * @delims: the delimiter string.
 *
 * Return: a pointer to an array of strings, or NULL on failure.
 */
char **strtow(char *str, char *delims)
{
	int i, j, k, m, numwords = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	if (!delims)
		delims = " ";

	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], delims) && (is_delim(str[i + 1], delims) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);

	words = malloc((1 + numwords) * sizeof(char *));
	if (!words)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], delims))
			i++;

		k = 0;
		while (!is_delim(str[i + k], delims) && str[i + k])
			k++;

		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = 0;
	}

	words[j] = NULL;
	return (words);
}

/**
 * strtow2 - splits a string into words
 * @str: the input string
 * @delim: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char delim)
{
	int i, j, k, m, numwords = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delim && str[i + 1] == delim) ||
		    (str[i] != delim && !str[i + 1]) || str[i + 1] == delim)
			numwords++;

	if (numwords == 0)
		return (NULL);

	words = malloc((1 + numwords) * sizeof(char *));
	if (!words)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == delim && str[i] != '\0')
			i++;

		k = 0;
		while (str[i + k] != delim && str[i + k] != '\0')
			k++;

		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (m = 0; m < k; m++)
			words[j][m] = str[i++];

		words[j][m] = '\0';
	}

	words[j] = NULL;
	return (words);
}

/**
 * _strlen - returns the length of a string.
 * @string: the string whose length to check.
 *
 * Return: integer length of string.
 */
int _strlen(char *string)
{
	int i = 0;

	if (!string)
		return (0);

	while (*string++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @string1: the first string.
 * @string2: the second string.
 *
 * Return: negative if string1 < string2, positive if string1 > string2,
 *			and zero if string1 == string2.
 */
int _strcmp(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);

		string1++;
		string2++;
	}

	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack.
 * @haystack: string to search.
 * @needle: the substring to find.
 *
 * Return: address of next char of haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
