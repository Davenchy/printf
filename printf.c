#include <stdio.h>
#include "main.h"
#include "style.h"

/**
 * process_printf - divide _printf fun to decrease code and process data
 * @format: pointer to cstring, which is the _printf format argument
 * @formats: pointer to array of predefined printf format cases
 * @ctx: pointer to the printf context object
 */
void process_printf(const char *format, format_t *formats, context_t *ctx)
{
	for (; *format; format++)
	{
		format_t *style_format;

		/* print ordinary characters */
		if (*format != '%')
		{
			pchar(ctx, *format);
			continue;
		}

		format++;
		ctx->format = format;
		style_reset(ctx->sp);
		style_format = style_detect(formats, format, ctx->sp);
		if (!style_format)
			continue;
		style_format->fun(ctx);
		format += ctx->sp->size;
	}
}

/**
 * _printf - simple clone for the printf function
 * @format: reference to the format string
 * Description: only implemented c, s, i, d, %
 * Return: number of characters had been written
 */
int _printf(const char *format, ...)
{
	context_t ctx;
	format_t formats[] = {
		{ 'c', case_c }, { 's', case_s }, { '%', case_mod },
		{ 'd', case_dec }, { 'i', case_dec }, { 'r', case_rs },
		{ 'u', case_unsigned }, { 'o', case_octal }, { 'b', case_bin },
		{ 'x', case_lower_hex }, { 'X', case_upper_hex }, {'p', case_address },
		{'R', case_R13 }, {'S', case_S }, { 0, (void *)0 }
	};

	if (!format)
		goto end;
	ctx.bp = buffer_start(BUFFER_SIZE);
	if (!ctx.bp)
		goto end;
	ctx.sp = style_create();
	if (!ctx.sp)
		goto end_buffer;
	va_start(ctx.ap, format);

	process_printf(format, formats, &ctx);

	style_destroy(ctx.sp);
	va_end(ctx.ap);
	return (buffer_end(ctx.bp));
end_buffer:
	buffer_end(ctx.bp);
end:
	return (-1);
}
