#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    double x1, x2;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    if (a == 0 && b == 0) {
        printf("Изродено уравнение");
    } else if (a == 0) {
        double x = (double)(-c) / b;
        printf("x = %lf", x);
    } else {
        double d = pow(b, 2) - 4 * a * c;
        double re = (double)(-b) / (2 * a);
        double im = (double)(sqrt(fabs(d))) / (2 * a);
        if (d > 0) {
            x1 = re + im;
            x2 = re - im;
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        } else if (d == 0) {
            x1 = re;
            x2 = re;
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        } else {
            printf("x1 = %lf + %lf*i\n", re, im);
            printf("x2 = %lf - %lf*i\n", re, im);
        }
    }

    return 0;
}
