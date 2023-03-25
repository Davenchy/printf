#include <unistd.h>

/**
 * pchar - writes character to stdout
 * @c: character to print
 * Return: 1 on success else 0
 */
int pchar(const char c) {
    return write(1, &c, 1) > 0 ? 1 : 0;
}

/**
 * pstr - writes string to stdout
 * @str: reference to cstring to print
 * Return: number of characters had been written
 */
int pstr(const char *str) {
    int i = 0;
    while (*str)
        i += pchar(*str++);
    return i;
}
