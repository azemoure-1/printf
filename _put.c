#include "main.h"
#include <unistd.h>

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: number of characters printed
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	_putchar('\n');
	return (str - a + 1);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print 
 *
 * Return: on success 1.
 * on error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

