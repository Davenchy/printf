#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include "buffer.h"

/* type definitions */
typedef struct context_s
{
	buffer_t bp;
	va_list ap;
	const char *format;
} context_t;
typedef struct
{
	char fcase;
	void (*fun)(context_t *ctx);
} format_t;

/* main and util functions */
int _printf(const char *format, ...);
void pchar(context_t *ctx, const char c);
void pstr(context_t *ctx, const char *str);
void strrev(char *str, int len);
int number_converter(char *str, unsigned long value, int base);

/* format functions */
void case_c(context_t *ctx);
void case_s(context_t *ctx);
void case_rs(context_t *ctx);
void case_mod(context_t *ctx);
void case_dec(context_t *ctx);
void case_bin(context_t *ctx);
void case_unsigned(context_t *ctx);
void case_octal(context_t *ctx);
void case_upper_hex(context_t *ctx);
void case_lower_hex(context_t *ctx);
void case_address(context_t *ctx);
void case_R13(context_t *ctx);
void case_S(context_t *ctx);

#endif
