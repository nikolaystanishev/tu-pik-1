#include <stdio.h>

int main() {
    int n, s = 0, num, k;

    do {
        printf("Брой на числата n = ");
        k = scanf("%d", &n);
        while (getchar() != '\n');
    } while (k != 1 || n < 0);

    for (int i = 0; i < n; i++) {
        do {
            printf("Въведи число num = ");
            k = scanf("%d", &num);
            while (getchar() != '\n');
        } while (k != 1);
        if (num > 0 && num % 2 == 0) {
            s += num;
        }
    }

    if (s == 0) {
        printf("Няма ...");
    } else {
        printf("s = %d", s);
    }

    return 0;
}
