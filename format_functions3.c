#include <ctype.h>
#include "main.h"
#include <string.h>

/**
 * case_address - function to handle pointer address format
 * @ctx: the printf context object
 */
void case_address(context_t *ctx)
{
	unsigned long value = va_arg(ctx->ap, unsigned long);
	char str[19];

	if (!value)
	{
		pstr(ctx, "(nil)");
		return;
	}

	str[0] = '0';
	str[1] = 'x';
	if (number_converter(str + 2, value, 16))
		pstr(ctx, str);
}

/**
 * case_R13 - handle root13 algorithm case
 * @ctx: the printf context object
 */
void case_R13(context_t *ctx)
{
	char *str = va_arg(ctx->ap, char *);

	if (!str)
		return;
	for (; *str; str++)
	{
		if (*str >= 65 && *str <= 90)
			pchar(ctx, ((90 - *str) >= 13) ? *str + 13 : *str - 13);
		else if (*str >= 97 && *str <= 122)
			pchar(ctx, ((122 - *str) >= 13) ? *str + 13 : *str - 13);
		else
			pchar(ctx, *str);
	}
}

/**
 * case_S - handle case of printting only printable characters
 * @ctx: the printf context object
 */
void case_S(context_t *ctx)
{
	char *str = va_arg(ctx->ap, char *);

	if (!str)
		return;
	for (; *str; str++)
	{
		char str_2[5];

		/* if character is printable the print it */
		if (isprint(*str))
		{
			pchar(ctx, *str);
			continue;
		}

		/* print byte in hexdec form */
		str_2[0] = '\\';
		str_2[1] = 'x';

		number_converter(str_2 + 2, *str, 16); /* convert byte into hexdec*/

		if (strlen(str_2) == 3)
		{
			str_2[3] = toupper(str_2[2]);
			str_2[2] = toupper('0');
			pstr(ctx, str_2);
		}
		else
		{
			str_2[2] = toupper(str_2[2]);
			str_2[3] = toupper(str_2[3]);
			pstr(ctx, str_2);
		}
	}
}
