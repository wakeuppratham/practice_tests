#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    int result = bitAnd(6, 5);
    printf("%d\n", result);
    return 0;
}
