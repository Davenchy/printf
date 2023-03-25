#include "main.h"

/**
 * case_num - function to handle numbers format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_num(va_list ap)
{
	int i = 0, sign = 0;
	/*
	 * allocate 10 bytes as max int is 10 chars (2,147,483,647)
	 * and 1byte for '-' sign if needed
	 * also 1byte for the NULL character
	 */
	char data[12];
	/* read next _printf function argument as an int */
	int val = va_arg(ap, int);

	/* check if val is an negative number */
	if (val < 0)
	{
		val = -val;
		sign = 1;
		data[i++] = '-';
	}

	/* convert digits into ascii string */
	while (val || !i)
	{
		data[i++] = val % 10 + '0';
		val /= 10;
	}
	data[i] = 0; /* set null character at the end */

	/*
	 * reverse the parsed characters
	 * because the code parsed the digits in reverse order
	 */
	strrev(data + sign, i - sign - 1);
	return (pstr(data));
}
