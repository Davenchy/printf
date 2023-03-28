#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

/**
 * buffer_start - initialize buffer object with @size bytes
 * @size: number of bytes allocated for the buffer
 * Return: buffer object otherwise NULL
 */
buffer_t buffer_start(size_t size)
{
	buffer_t bp = malloc(sizeof(struct buffer_info_s));

	if (!bp)
		return (NULL);
	bp->pointer = 0;
	bp->written = 0;
	bp->size = size;
	bp->buffer = calloc(size, sizeof(char));
	if (!bp->buffer)
	{
		free(bp);
		return (NULL);
	}
	return (bp);
}

/**
 * buffer_end - flush data if any then free the buffer object from memory
 * @bp: the buffer object
 * Return: number of written bytes by this buffer object
 */
size_t buffer_end(buffer_t bp)
{
	size_t written = 0;

	buffer_flush(bp); /* write remaining data if any */
	written = bp->written;
	/* free memory */
	free(bp->buffer);
	free(bp);
	return (written);
}

/**
 * buffer_flush - write data in the buffer to the stdout
 * @bp: the buffer object
 * Return: number of bytes written
 */
size_t buffer_flush(buffer_t bp)
{
	ssize_t r;

	/* if no data to print then return 0 */
	if (!bp->pointer)
		return (0);
	/* write data to stdout and counter written bytes */
	r = write(1, bp->buffer, bp->pointer);
	bp->pointer = 0; /* reset buffer pointer */
	bp->written += r < 0 ? 0 : r; /* count written bytes */
	return (r < 0 ? 0 : r);
}

/**
 * buffer_write - writes data to buffer and flush on full
 * @bp: the buffer object
 * @str: cstring or data to write to buffer
 * @size: size of bytes to write to the buffer
 * Return: number of bytes had been flushed otherwise 0 with errno set
 */
size_t buffer_write(buffer_t bp, const char *str, size_t size)
{
	size_t written = 0; /* tracks written data */

	while (size - written)
	{
		size_t towrite = size - written;
		size_t space = bp->size - bp->pointer;

		/* if buffer is full the flush before continue */
		if (!space && !buffer_flush(bp))
			return (0);

		/* if data to write is less than or equal remaining space in buffer */
		if (towrite <= space)
		{
			strcpy(bp->buffer + bp->pointer, str + written);
			bp->pointer += towrite;
			written += towrite;
		}
		/* if data to write is more than remaining space in buffer */
		else
		{
			/* copy data to the remaining space */
			strncpy(bp->buffer + bp->pointer, str + written, space);
			bp->pointer += space;
			written += space;
		}
	}

	/* make sure to flush buffer if full */
	if (!(bp->size - bp->pointer) && !buffer_flush(bp))
		return (0);
	return (written);
}

/**
 * buffer_write_char - write character to the buffer
 * @bp: the buffer object
 * @c: the character to write
 * Return: 1 on success otherwise 0 on fail with errno set
 */
unsigned char buffer_write_char(buffer_t bp, const char c)
{
	size_t space = bp->size - bp->pointer;

	/* if no space before write then flush */
	if (!space && !buffer_flush(bp))
		return (0);
	/* write character to the buffer */
	bp->buffer[bp->pointer++] = c;
	/* if no space after write then flush */
	if (!(space - 1) && !buffer_flush(bp))
		return (0);
	return (1);
}
