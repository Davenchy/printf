#include "../main.h"

int main(void)
{
    char *name = "mostafa @Elmasry";

    int r = _printf("%R\n", name);
    _printf("length : %d", r);
    return (0);
}
