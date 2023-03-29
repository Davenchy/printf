#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * style_create - create style object
 * Return: style object on success otherwise NULL
 */
style_t style_create(void)
{
	style_t sp = calloc(1, sizeof(struct style_s));

	if (!sp)
		return (NULL);
	return (sp);
}

/**
 * style_destroy - free style object from the memory
 * @sp: the style object
 */
void style_destroy(style_t sp)
{
	free(sp);
}

/**
 * style_reset - reset style object before every use
 * @sp: the style object
 */
void style_reset(style_t sp)
{
	memset(sp, 0, sizeof(struct style_s));
}
