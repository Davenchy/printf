#include <limits.h>
#include "../main.h"

int main() {
    int r;
    r = _printf("char: %c, string: %s, mod: %%\n", 'A', "Hello, World!");
    _printf("length: %d\n", r);
    r = _printf("number: %d, zero: %i, negative: %d\n", 10, 0, -50);
    _printf("length: %d\n", r);
    r = _printf("null: %s\n", (void *)0);
    _printf("length: %d\n", r);
    r = _printf((void *)0);
    _printf("length: %d\n", r);
    r = _printf("");
    _printf("length: %d\n", r);
		_printf("\n");
		_printf("%d, %d, %i, %i\n", INT_MAX, INT_MIN, INT_MAX, INT_MIN);
    return 0;
}
