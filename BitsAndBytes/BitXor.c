#include <stdio.h>

int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int main() {
    int result = bitXor(4, 5);
    printf("%d\n", result);
    return 0;
}
