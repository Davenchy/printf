#ifndef _BUFFER_H_
#define _BUFFER_H_
#define BUFFER_SIZE 1024

#include <stddef.h>

/**
 * struct buffer_info_s - a structure to define the buffer object
 * @buffer: pointer to the buffer data
 * @pointer: the pointer or the cursor the points to the end of the buffer
 * @size: the size of the buffer
 * @written: the number of written bytes to the stdout
 */
struct buffer_info_s
{
	char *buffer;
	size_t pointer;
	size_t size;
	size_t written;
};
typedef struct buffer_info_s *buffer_t;

buffer_t buffer_start(size_t size);
size_t buffer_end(buffer_t bp);
size_t buffer_flush(buffer_t bp);
size_t buffer_write(buffer_t bp, const char *str, size_t size);
unsigned char buffer_write_char(buffer_t bp, const char c);

#endif
