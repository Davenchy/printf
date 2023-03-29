#include <ctype.h>
#include <string.h>
#include "types.h"

/**
 * isstyle - check if char @c is a predefined format case
 * @formats: pointer to predefined format cases array
 * @c: the character to check
 * Return: format case object if any match otherwise NULL
 */
format_t *isstyle(format_t *formats, const char c)
{
	for (; formats->fcase; formats++)
		if (formats->fcase == c)
			return (formats);
	return (NULL);
}

/**
 * format_case_detect - divide the main style detect function
 * @str: the string to read
 * @sp: the style object
 * @formats: the format cases list
 * Return: format object otherwise NULL
 */
format_t *format_case_detect(const char *str, style_t sp, format_t *formats)
{
	int i = 0;
	format_t *format;

	if (*str == '0')
	{
		sp->zero_fill = 1;
		i++;
	}

	for (; *str && (isdigit(*str) || *str == '.'); str++, i++)
	{
		/* todo: support '.' detection */
		sp->padding *= 10;
		sp->padding += *str - '0';
	}

	format = isstyle(formats, *str);
	if (format)
	{
		sp->fcase = format->fcase;
		sp->size += i;
	}

	return (format);
}

/**
 * style_detect - detect style specification starting from @str pointer
 * @formats: a pointer to a predefined format cases array
 * @str: the cstring to parse
 * @sp: a style object
 * Return: detected format case otherwise NULL
 */
format_t *style_detect(format_t *formats, const char *str, style_t sp)
{
	int i;
	format_t *format = NULL;

	sp->bytes = str;
	for (i = 0; str[i]; i++)
	{
		char c = str[i];

		if (strchr("+ -#lh", c))
		{
			if (c == '#')
				sp->leading_zero = 1;
			else if (c == 'l')
				sp->islong = 1;
			else if (c == 'h')
				sp->isshort = 1;
			else if (!sp->sign)
				sp->sign = c;
			continue;
		}
		break;
	}

	sp->size = i;
	format = format_case_detect(str + i, sp, formats);
	return (format);
}
