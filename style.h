#ifndef _STYLE_H_
#define _STYLE_H_
#include "types.h"

style_t style_create();
void style_destroy(style_t sp);
void style_reset(style_t sp);
format_t * style_detect(format_t *formats, const char *str, style_t sp);

#endif
