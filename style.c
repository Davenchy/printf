#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "types.h"

style_t style_create() {
	style_t sp = calloc(1, sizeof(struct style_s));
	if (!sp)
		return (NULL);
	return (sp);
}

void style_destroy(style_t sp) {
	free(sp);
}

void style_reset(style_t ap) {
	memset(ap, 0, sizeof(struct style_s));
}

format_t *isstyle(format_t *formats, const char c) {
	for (; formats->fcase; formats++)
		if (formats->fcase == c)
			return formats;
	return NULL;
}

format_t *style_detect(format_t *formats, const char *str, style_t sp) {
	int i, isnum = 0;
	format_t *format = NULL;

	sp->bytes = str;
	for (i = 0; str[i]; i++) {
		char c = str[i];

		if (isdigit(c)) {
			if (c == '0' && !isnum) {
				sp->zero_fill = 1;
				continue;
			}
			sp->padding *= (isnum) ? 10 : 1;
			sp->padding += str[i] - '0';
			isnum = 1;
			continue;
		} else {
			isnum = 0;
		}

		if (!sp->sign && strchr("+ -", c))
			sp->sign = c;
		else if (c == '#')
			sp->leading_zero = 1;
		else if (c == 'l')
			sp->islong = 1;
		else if (c == 'h')
			sp->isshort = 1;
		else if ((format = isstyle(formats, c))) {
			sp->fcase = c;
			sp->size = i;
			break;
		}
		else break;
		continue;
	}

	return format;
}
