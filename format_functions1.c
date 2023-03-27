#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * case_c - function to handle char format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_c(va_list ap)
{
	return (pchar(va_arg(ap, int)));
}

/**
 * case_s - function to handle cstring format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_s(va_list ap)
{
	return (pstr(va_arg(ap, char *)));
}

/**
 * case_rs - function to handle reverse cstring format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_rs(va_list ap)
{
	int counter;
	char *s = va_arg(ap, char *);
	char *copy = strdup(s);

	if (!copy)
		return (0);
	strrev(copy, strlen(copy));
	counter = pstr(copy);
	free(copy);
	return (counter);
}

/**
 * case_mod - function to handle mod format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_mod(va_list ap __attribute__((unused)))
{
	return (pchar('%'));
}

/**
 * case_dec - function to handle decimal numbers formatting
 * @ap: pointer to the variadic list
 * Return: number of characters had been writter
 */
int case_dec(va_list ap)
{
	int sign = 0, value = va_arg(ap, int);
	char str[12];

	if (value < 0)
	{
		value = -value;
		str[sign++] = '-';
	}

	if (!number_converter(str + sign, value, 10))
		return (0);
	return (pstr(str));
}
