#ifndef _FORMAT_H_
#define _FORMAT_H_
#include <stdarg.h>
#include "buffer.h"

/**
 * struct style_s - structure to hold the format info
 * @fcase: the format case
 * @sign: the format sign case {non, +, -, space}
 * @zero_fill: whether fill padding with zero or not
 * @leading_zero: whether add zero format as prefix or not
 * @islong: whether to parse number as 8bytes or not
 * @isshort: whether to parse number as 2bytes or not
 * @padding: the number of output fields
 * @size: the number of bytes of the detected format case - 1
 * @bytes: the characters of the detected format case
 */
struct style_s
{
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

/**
 * struct context_s - the printf context object
 * @ap: the arguments pointer object
 * @bp: the buffer pointer object
 * @format: pointer to the current char in the printf format
 * @sp: the style pointer object
 */
typedef struct context_s
{
	va_list ap;
	buffer_t bp;
	const char *format;
	style_t sp;
} context_t;

/**
 * struct format_s - struct to hold the format case handler
 * @fcase: the format case character
 * @fun: the format case handler function
 */
typedef struct format_s
{
	char fcase;
	void (*fun)(context_t *ctx);
} format_t;

#endif
