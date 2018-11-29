#include <stdio.h>

int main() {
    int a, b, c;


    printf("Въведете а = ");
    scanf("%d", &a);
    printf("Въведете b = ");
    scanf("%d", &b);
    printf("Въведете c = ");
    scanf("%d", &c);

    if (a > b) {
        if (a > c) {

            printf("a = %d - най-голямо", a);
        } else {
            printf("c = %d - най-голямо", c);
        }
    } else if (b > c) {
        printf("b = %d - най-голямо", b);
    } else {
        printf("c = %d - най-голямо", c);
    }

    return 0;
}
