#include <stdio.h>
#include <errno.h>
#include <limits.h>


int main() {
    int x, y;
    x = y = 6;

    x *= (y = 5);
    printf("x = %d", x);

    int num;
    scanf("%d", &num);
    if (errno == 34) {

    }

    num = INT_MAX;
    num += 1;

    int k = 0;

    __asm (
        "pushf;"
        "jo overflow;"
        "jmp ok;"
        "overflow:"
        "mov dword ptr[k], 1;"
        "ok:"
        "popf;");

    if (k == 1) {
        printf("overflow\n");
    }
    // for float is_inf from math.h

    return 0;
}

