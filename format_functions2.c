#include <ctype.h>
#include "main.h"

/**
 * case_bin - function to handle binary format
 * @ctx: the printf context object
 */
void case_bin(context_t *ctx)
{
	unsigned int value = va_arg(ctx->ap, unsigned int);
	char str[35];

	if (number_converter(str, value, 2))
		pstr(ctx, str);

}

/**
 * case_unsigned - function to handle unsigned decimal numbers format
 * @ctx: the printf context object
 */
void case_unsigned(context_t *ctx)
{
	unsigned long int value = va_arg(ctx->ap, unsigned long int);
	char str[23];

	if (ctx->sp->isshort)
		value = (unsigned short) value;
	else if (!ctx->sp->islong)
		value = (unsigned int) value;

	if (number_converter(str, value, 10))
		pstr(ctx, str);
}

/**
 * case_octal - function to handle octal numbers format
 * @ctx: the printf context object
 */
void case_octal(context_t *ctx)
{
	unsigned int value = va_arg(ctx->ap, unsigned int);
	char str[12];

	if (number_converter(str, value, 8))
		pstr(ctx, str);
}

/**
 * case_lower_hex - function to handle lower case hexdec format
 * @ctx: the printf context object
 */
void case_lower_hex(context_t *ctx)
{
	unsigned int value = va_arg(ctx->ap, unsigned int);
	char str[10];

	if (number_converter(str, value, 16))
		pstr(ctx, str);
}

/**
 * case_upper_hex - function to handle uppercase hexdec format
 * @ctx: the printf context object
 */
void case_upper_hex(context_t *ctx)
{
	unsigned int i, value = va_arg(ctx->ap, unsigned int);
	char str[10];

	if (number_converter(str, value, 16))
	{
		for (i = 0; str[i]; i++)
			str[i] = toupper(str[i]);
		pstr(ctx, str);
	}
}
