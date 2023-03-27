#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stddef.h>

/* main and util functions */
int _printf(const char *format, ...);
int pchar(const char c);
int pstr(const char *str);
void strrev(char *str, int len);
int number_converter(char *str, unsigned long value, int base);

/* type definitions */
typedef int (*format_f)(va_list);
typedef struct
{
	char fcase;
	format_f fun;
} format_s;

/* format functions */
int case_c(va_list);
int case_s(va_list);
int case_rs(va_list);
int case_mod(va_list);
int case_dec(va_list);
int case_bin(va_list);
int case_unsigned(va_list);
int case_octal(va_list);
int case_upper_hex(va_list);
int case_lower_hex(va_list);
int case_address(va_list);

#endif
