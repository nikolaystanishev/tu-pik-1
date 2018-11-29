#include <stdio.h>

int* sum(int, int);

int main() {
    int a = 5, b = 6;
    int *return_values;
    return_values = sum(a, b);
    printf("s = %d", return_values[0]);
    printf("d = %d", return_values[1]);
    return 0;
}

int* sum(int a, int b) {
    static int return_values[2];
    return_values[0] = a + b;
    return_values[1] = a - b;
    return return_values;
}
