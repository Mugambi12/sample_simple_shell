#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination buffer
 * @src: pointer to the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;

	return (ret);
}

/**
 * _strcpy - Copies a string.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source buffer.
 *
 * Return: Pointer to destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;

	return (dest);
}

/**
 * _strdup - duplicates a string.
 * @str: the string to duplicate.
 *
 * Return: pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;

	return (ret);
}

/**
 *_puts - prints an input string.
 *@str: the string to be printed.
 *
 * Return: void.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character `c` to stdout
 * @character: The character to print
 *
 * Return: On success, returns 1.
 *				On error, returns -1 and sets errno appropriately.
 */
int _putchar(char character)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (character != BUF_FLUSH)
		buf[i++] = character;

	return (1);
}
