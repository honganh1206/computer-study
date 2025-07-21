#include <stdio.h>

int sumr(int n) {
    if (n <= 0) {
        return 0;
    }

    return n + sumr(n-1);
}

int main(void) {
    int x = 10;
    x = sumr(x);
    printf("x is %d\n", x);
    return 0;
}
