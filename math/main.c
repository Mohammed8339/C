#include <stdio.h>
#include <math.h>
#include "pow.c"

int main() {

    int x = 3;
    int y = (2 * power(x, 2) + 3);
    int res = power(x, 2);
    printf("x = %d\n", res);
    printf("y = %d\n", y);
    return 0;
}
