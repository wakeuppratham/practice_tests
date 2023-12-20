#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int result = getByte(0x12345678, 1);
    printf("0x%X\n", result);
    return 0;
}
