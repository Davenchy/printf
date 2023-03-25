#include <unistd.h>

/**
 * pchar - writes character to stdout
 * @c: character to print
 * Return: 1 on success else 0
 */
int pchar(const char c)
{
	return (write(1, &c, 1) > 0 ? 1 : 0);
}

/**
 * pstr - writes string to stdout
 * @str: reference to cstring to print
 * Return: number of characters had been written
 */
int pstr(const char *str)
{
	int i = 0;

	while (*str)
		i += pchar(*str++);
	return (i);
}

/**
 * strrev - reverse array of characters of length @len
 * @str: reference to the characters array
 * @len: the size of the array
 */
void strrev(char *str, int len)
{
	char *ptr;

	for (ptr = str + len; str < ptr; str++, ptr--)
		/* swap *str with *ptr */
		*str ^= *ptr, *ptr ^= *str, *str ^= *ptr;
}
