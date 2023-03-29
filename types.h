#ifndef _FORMAT_H_
#define _FORMAT_H_
#include <stdarg.h>
#include "buffer.h"

struct style_s {
	char fcase;
	char sign;
	char zero_fill;
	char leading_zero;
	char islong;
	char isshort;
	int padding;
	unsigned int size;
	const char *bytes;
};
typedef struct style_s *style_t;

typedef struct context_s
{
	va_list ap;
	buffer_t bp;
	const char *format;
	style_t sp;
} context_t;

typedef struct
{
	char fcase;
	void (*fun)(context_t *ctx);
} format_t;

#endif
