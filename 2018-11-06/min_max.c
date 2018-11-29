#include <stdio.h>

#define arr_LENGTH 10

int main() {
    int arr[arr_LENGTH];
    int k;
    int max = 0, max_ind = 0;

    for (int i = 0; i < arr_LENGTH; i++) {
        do {
            printf("Въведете arr[%d] = ", i);
            k = scanf("%d", &(*(arr + i)));
            while (getchar() != '\n');
        } while (k == 0 || i < 0 || i >= arr_LENGTH);
    }

    for (int i = 0; i < arr_LENGTH; i++) {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }

    for (int i = 0; i < arr_LENGTH; i++) {
        if (i == 0) {
            max = *arr;
            max_ind = i;
            continue;
        }
        if (max < *(arr + i)) {
            max = *(arr + i);
            max_ind = i;
        }
    }

    printf("Max = %d, Max index = %d\n", max, max_ind);
    return 0;
}
