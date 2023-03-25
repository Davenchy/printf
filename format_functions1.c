#include "main.h"

/**
 * case_c - function to handle char format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_c(va_list ap) {
    return pchar(va_arg(ap, int));
}

/**
 * case_s - function to handle cstring format
 * @ap: pointer to the variadic list
 * Description:
 * if the string argument equals to NULL then prints "(null)"
 * Return: number of characters had been written
 */
int case_s(va_list ap) {
    char *str = va_arg(ap, char *);
    if (!str)
        return pstr("(null)");
    return pstr(str);
}

/**
 * case_mod - function to handle mod format
 * @ap: pointer to the variadic list
 * Return: number of characters had been written
 */
int case_mod(va_list ap __attribute__((unused))) {
    return pchar('%');
}
