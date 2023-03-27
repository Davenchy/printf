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
 * Description:
 * if @str is NULL the prints `(null)`
 * Return: number of characters had been written
 */
int pstr(const char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
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
