#include <stdio.h>
#include "../main.h"

int main() {
    int r;
    r = _printf("char: %c, string: %s, mod: %%\n", 'A', "Hello, World!");
    printf("length: %d\n", r);
    return 0;
}
