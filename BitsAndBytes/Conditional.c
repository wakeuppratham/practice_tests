#include <stdio.h>

int conditional(int x, int y, int z) {
    return ((!x + ~0) & y) | ((!!x + ~0) & z);
}

int main() {
    int result = conditional(2, 4, 5);
    printf("%d\n", result);
    return 0;
}
