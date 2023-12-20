#include <stdio.h>

int sign(int x) {
    return (x >> 31) | (!!x);
}

int main() {

   int  result = sign(-23);
    printf("%d\n", result);
    return 0;
}
