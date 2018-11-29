#include <stdio.h>

int main() {
    int begin, end;
    int max = 0, num;
    int k, flag = 0;;

    do {
        printf("begin = ");
        k = scanf("%d", &begin);
        while (getchar() != '\n');
    } while (k == 0);
    do {
        printf("end = ");
        k = scanf("%d", &end);
        while (getchar() != '\n');
    } while (k == 0 || begin >= end);

    while (1) {
        printf("y/n");
        k = getchar();
        if (k == 'n') {
            break;
        }

        do {
            printf("num = ");
            k = scanf("%d", &num);
            while (getchar() != '\n');
        } while (k == 0);

        if (flag == 0 && num > begin && num < end && num < 0) {
            max = num;
            flag = 1;
        }
        if (flag == 1 && num > begin && num < end && num < 0 && num > max) {
            max = num;
        }
    }

    if (flag == 0) {
        printf("No numbers");
    } else {
        printf("max = %d", max);
    }


    return 0;
}

