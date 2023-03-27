#include "main.h"

/**
 * case_address - function to handle pointer address format
 * @ap: the variadic list pointer
 * Return: number of characters had been printed
 */
int case_address(va_list ap)
{
	unsigned long value = va_arg(ap, unsigned long);
	char str[19];

	if (!value)
		return pstr("(nil)");

	str[0] = '0';
	str[1] = 'x';
	if (!number_converter(str + 2, value, 16))
		return (0);
	return (pstr(str));
}

