#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * case_c - function to handle char format
 * @ctx: the printf context object
 */
void case_c(context_t *ctx)
{
	pchar(ctx, va_arg(ctx->ap, int));
}

/**
 * case_s - function to handle cstring format
 * @ctx: the printf context object
 */
void case_s(context_t *ctx)
{
	pstr(ctx, va_arg(ctx->ap, char *));
}

/**
 * case_rs - function to handle reverse cstring format
 * @ctx: the printf context object
 */
void case_rs(context_t *ctx)
{
	char *s = va_arg(ctx->ap, char *);
	char *copy = strdup(s);

	if (!copy)
		return;
	strrev(copy, strlen(copy));
	pstr(ctx, copy);
	free(copy);
}

/**
 * case_mod - function to handle mod format
 * @ctx: the printf context object
 */
void case_mod(context_t *ctx)
{
	pchar(ctx, '%');
}

/**
 * case_dec - function to handle decimal numbers formatting
 * @ctx: the printf context object
 */
void case_dec(context_t *ctx)
{
	int sign = 0;
	unsigned int value = va_arg(ctx->ap, unsigned int);
	char str[12];

	if ((signed)value < 0)
	{
		value = -value;
		str[sign++] = '-';
	}

	if (!number_converter(str + sign, value, 10))
		return;
	pstr(ctx, str);
}
