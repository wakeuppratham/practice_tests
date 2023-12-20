#include <stdio.h>

int logicalShift(int x, int n) {
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}

int main() {
    int result = logicalShift(0x87654321, 4);
    printf("0x%X\n", result);
    return 0;
}
