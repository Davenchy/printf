#include <ctype.h>
#include "main.h"

/**
 * case_bin - function to handle binary format
 * @ap: pointer to the variadic list
 * Return: number of characters had been printed
 */
int case_bin(va_list ap)
{
	unsigned int value = va_arg(ap, unsigned int);
	char str[35];

	if (!number_converter(str, value, 2))
		return (0);
	return (pstr(str));
}

/**
 * case_unsigned - function to handle unsigned decimal numbers format
 * @ap: pointer to the variadic list
 * Return: number of characters had been printed
 */
int case_unsigned(va_list ap)
{
	unsigned int value = va_arg(ap, unsigned int);
	char str[11];

	if (!number_converter(str, value, 10))
		return (0);
	return (pstr(str));
}

/**
 * case_octal - function to handle octal numbers format
 * @ap: pointer to the variadic list
 * Return: number of characters had been printed
 */
int case_octal(va_list ap)
{
	unsigned int value = va_arg(ap, unsigned int);
	char str[12];

	if (!number_converter(str, value, 8))
		return (0);
	return (pstr(str));
}

/**
 * case_lower_hex - function to handle lower case hexdec format
 * @ap: pointer to the variadic list
 * Return: number of characters had been printed
 */
int case_lower_hex(va_list ap)
{
	unsigned int value = va_arg(ap, unsigned int);
	char str[10];

	if (!number_converter(str, value, 16))
		return (0);
	return (pstr(str));
}

/**
 * case_upper_hex - function to handle uppercase hexdec format
 * @ap: pointer to the variadic list
 * Return: number of characters had been printed
 */
int case_upper_hex(va_list ap)
{
	unsigned int i, value = va_arg(ap, unsigned int);
	char str[10];

	if (!number_converter(str, value, 16))
		return (0);

	for (i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (pstr(str));
}
