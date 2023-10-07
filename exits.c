#include "shell.h"

/**
 * _strncpy - Copies a string up to a maximum of 'n' characters
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the maximum number of characters to copy
 * Return: a pointer to the destination string 'dest'
 */
char *_strncpy(char *dest, const char *src, int n)
{
	char *original_dest = dest;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (original_dest);
}

/**
 * _strncat - Concatenates two strings, up to a maximum of 'n' characters
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of characters to concatenate
 * Return: a pointer to the destination string 'dest'
 */
char *_strncat(char *dest, const char *src, int n)
{
	char *original_dest = dest;

	while (*dest != '\0')
		dest++;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}

	if (n > 0)
		*dest = '\0';

	return ((original_des)t);
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: the string to be searched
 * @c: the character to look for
 * Return:  pointer to the first occurrence of 'c' in 's', or NULL if not found
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (((char *))s);
		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (NULL);
}
