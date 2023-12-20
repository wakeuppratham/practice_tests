#include <stdio.h>

int invert(int x, int p, int n) {
    int mask = (~(~0 << n)) << p;
    return x ^ mask;
}

int main() {
    int result = invert(0xABCDEF01, 8, 8);
    printf("0x%X\n", result);
    return 0;
}
