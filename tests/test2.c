#include "../main.h"

int main() {
    int r;
    r = _printf("char: %c, string: %s, mod: %%\n", 'A', "Hello, World!");
    _printf("length: %d\n", r);
    r = _printf("number: %d, zero: %i, negative: %d\n", 10, 0, -50);
    _printf("length: %d\n", r);
    return 0;
}
