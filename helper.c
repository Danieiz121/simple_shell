#include "string.h"

/**
 * _strcpy - copies a string
 * @src: source to copy from
 * @dest: destination to be copied to
 * Return: empty
 */
void _strcpy(char *src, char *dest)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

/**
 * _strlen - calculates the length of a string
 * @str: string to be calculated
 * Return: length of a string
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (len);
	}
	for (; str[len] != '\0'; len++)
	{
		;
	}
	return (len);
}

/**
 * print - prints a string to stdout
 * @str: string to be printed
 * @stream: stream to print out to
 * Return: empty
 */
void print(char *str, int stream)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		write(stream, &str[i], 1);
	}
}

/**
 * tokenizer - tokenizes input and stores it into an array
 * @str: input to be parsed
 * @delim: delimiter to be used
 * Return: array of tokens
 */
char **tokenizer(char *str, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *saved_ptr = NULL;

	token = strtok_r(str, delim, &saved_ptr);
	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &saved_ptr);
		num_delim++;
	}
	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;
	return (av);
}

/**
 * rem_newline - removes newline from a string
 * @str: string to be used
 * Return: empty
 */
void rem_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			break;
		}
		i++;
	}
	str[i] = '\0';
}
