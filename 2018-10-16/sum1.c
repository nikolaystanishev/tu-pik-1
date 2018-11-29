#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, s = 0, num, k;
    while (1) {
        do {
            printf("Въведи число num = ");
            k = scanf("%d", &num);
            if (k == EOF) {
               break;
            }
            while (getchar() != '\n');
        } while (k != 1);
        if (ferror(stdin)) {
            printf("Грешка!");
            exit(1);
        } else if (k == EOF) {
            break;
        }
        if (num > 0 && num % 2 == 0) {
            s += num;
        }
    }

    if (s == 0) {
        printf("Няма ...");
    } else {
        printf("\ns = %d", s);
    }

    return 0;
}
