#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

/* main functions */
int _printf(const char *format, ...);
int pchar(const char c);
int pstr(const char *str);

/* type definitions */
typedef int (*format_f)(va_list);
typedef struct {
    char fcase;
    format_f fun;
} format_s;

/* format functions */
int case_c(va_list ap);
int case_s(va_list ap);
int case_mod(va_list ap);

#endif
