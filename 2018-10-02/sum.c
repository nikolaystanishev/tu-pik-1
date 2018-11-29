#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <Windows.h>
#include <stdlib.h>

int sum(int, int);

int main() {
    int a, b;
    // setConsoleOutputCP(1251);
    printf("a=");
    scanf("%d", &a);
    printf("\nb=");
    scanf("%d", &b);
    int s = sum(a, b);
    printf("\nСумата s=%d", s);
    return 0;
}

int sum(int a, int b) {
    return a + b;
}
