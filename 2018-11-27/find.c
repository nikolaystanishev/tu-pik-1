#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isdelimiter(char*, char);
bool isnumber(char*);


int main() {
    FILE *fp;
    char buff[256], word[30];
    int i = 0, j = 0;
    int count = 0, w_count = 0;
    bool InWord = false;
    char w[] = "include";

    char delimiter[] = {'[', ']', '(', ')', ';', '!', '=', '>', '<', '|', '*',
                        '/', '\\', ':', '&', '%', ' ', '\t', '\n', '#', '{',
                        '}', '\'', ',', '"', '-', '+', '.'};

    fp = fopen("find.c", "r");

    while (fgets(buff, 254, fp) != NULL) {
        i = 0;
        while(buff[i]) {
            if (InWord == false) {
                if (!isdelimiter(delimiter, buff[i])){
                    InWord = true;
                    word[j++] = buff[i];
                } else {
                    i++;
                    continue;
                }
            } else {
                if (isdelimiter(delimiter, buff[i])) {
                    InWord = false;
                    word[j] = '\0';
                    j = 0;
                    if (isnumber(word)) {
                        continue;
                    } else {
                        count++;
                        printf("\nword%d=%s", count, word);
                        if (!strcmp(word, w)) {
                            w_count += 1;
                        }
                    }
                } else {
                    word[j++] = buff[i];
                }
            }
            i++;
        }
    }

    printf("\n Брой на думите = %d", count);
    printf("\n Брой на думата - %s = %d", w, w_count);

    fclose(fp);

    return 0;
}

bool isdelimiter(char* delimiters, char c) {
    int i = 0;
    char d;
    while(d = delimiters[i++]) {
        if (d == c) {
            return true;
        }
    }
    return false;
}


bool isnumber(char* word) {
    int i = 0;
    char d;
    while(d = word[i++]) {
        if (!isdigit(d)) {
            return false;
        }
    }
    return true;
}
