#include "main.h"

/**
 * _printf - simple clone for the printf function
 * @format: reference to the format string
 * Description: only implemented c, s, i, d, %
 * Return: number of characters had been written
 */
int _printf(const char *format, ...)
{
	int i, counter = 0;
	va_list ap;
	/* array of format cases and their handling functions */
	format_s formats[] = {
		{ 'c', case_c }, { 's', case_s }, { '%', case_mod },
		{ 'd', case_dec }, { 'i', case_dec }, { 'r', case_rs },
		{ 'u', case_unsigned }, { 'o', case_octal }, { 'b', case_bin },
		{ 'x', case_lower_hex }, { 'X', case_upper_hex }, {'p', case_address },
		{ 0, (void *)0 }
	};

	if (!format)
		return (-1);
	va_start(ap, format);
	for (; *format; format++)
	{
		/* print ordinary characters */
		if (*format != '%')
		{
			pchar(*format);
			counter++;
			continue;
		}

		format++;
		/* print formats */
		for (i = 0; formats[i].fcase; i++)
		{
			/* detect the format case */
			if (formats[i].fcase == *format)
				/* execute the format handling function */
				counter += formats[i].fun(ap);
		}
	}
	va_end(ap);
	return (counter);
}
