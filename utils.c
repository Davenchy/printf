#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * pchar - writes character to stdout
 * @ctx: the printf context object
 * @c: character to print
 */
void pchar(context_t *ctx, const char c)
{
	buffer_write_char(ctx->bp, c);
}

/**
 * pstr - writes string to stdout
 * @ctx: the printf context object
 * @str: reference to cstring to print
 * Description:
 * if @str is NULL the prints `(null)`
 */
void pstr(context_t *ctx, const char *str)
{
	if (!str)
		str = "(null)";
	buffer_write(ctx->bp, str, strlen(str));
}

/**
 * strrev - reverse array of characters of length @len
 * @str: reference to the characters array
 * @len: the size of the array
 */
void strrev(char *str, int len)
{
	char *ptr;

	for (ptr = str + len - 1; str < ptr; str++, ptr--)
		/* swap *str with *ptr */
		*str ^= *ptr, *ptr ^= *str, *str ^= *ptr;
}

/**
 * number_converter - convert decimal number into string in @base form
 * @str: string buffer to write the output at
 * @value: the decimal number to be converted
 * @base: the base to convert the decimal number @value to
 * Return: 1 if success otherwise 0
 */
int number_converter(char *str, unsigned long value, int base)
{
	int i = 0;
	char *dict = "0123456789abcdef";

	if (base < 2 || base > 16)
		return (0);

	while (value || !i)
	{
		str[i++] = dict[value % base];
		value /= base;
	}
	str[i] = 0;

	strrev(str, i);
	return (1);
}
