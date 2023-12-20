#include <stdio.h>

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}

int main() {
    int result = bang(3);
    printf("%d\n", result);
    return 0;
}
