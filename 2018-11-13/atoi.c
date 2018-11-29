#include <stdio.h>

int main() {
    int num = 0;
    char ch, num_word[30];
    scanf("%d", &num);
    int i;
    for (i = 0; num != 0; i++) {
        ch = num % 10;
        num = num / 10;
        num_word[i] = '0' + ch;
    }
    num_word[i + 1] = '\0';
    for (; i >= 0; i--) {
        fputc(num_word[i], stdout);
    }
    return 0;
}
