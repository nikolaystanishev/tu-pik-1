#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


char* read_line(int);
char* read_file(const char*);
int get_num_of_words(char*);

int main() {
    if(write(STDOUT_FILENO, "Insert input file (for read from standard input enter stdin): ", 63) < 0) {
        perror("write");
        exit(-1);
    }
    char *input_file = read_line(STDIN_FILENO);
    if(input_file == NULL) {
        exit(0);
    }
    if(write(STDOUT_FILENO, "Insert output file (for read from standard output enter stdout): ", 66) < 0) {
        perror("write");
        exit(-1);
    }
    char *output_file = read_line(STDIN_FILENO);
    if(output_file == NULL) {
        exit(0);
    }

    read_file(input_file);
    return 0;
}

char* read_line(int fd) {
    unsigned long cmdlineSize = 0;
    char *cmdline = 0;
    char buff[1];
    long result;
    while((result = read(fd, buff, 1)) != 0) {
        if(result < 0) {
            perror("read");
            exit(-1);
        }
        if(buff[0] == EOF) {
            return NULL;
        } else if(buff[0] == '\n') {
            if (cmdlineSize == 0) {
                return (char*)"\n";
            }
            cmdlineSize++;
            cmdline = (char*)realloc(cmdline, cmdlineSize);
            if(cmdline == NULL) {
                perror("realloc");
                exit(-1);
            }
            cmdline[cmdlineSize - 1] = '\0';
            return cmdline;
        } 
        cmdlineSize++;
        cmdline = (char*)realloc(cmdline, cmdlineSize);
        if(cmdline == NULL) {
            perror("realloc");
            exit(-1);
        }
        cmdline[cmdlineSize - 1] = buff[0];
    }
    return NULL;
}

char* read_file(const char* file_name) {
    int fd = open(file_name, O_RDONLY);
    if(fd < 0) {
        perror("open");
        exit(-1);
    }

    char* line = NULL;

    while(1) {
        line = read_line(fd);
        if (line == NULL) {
            break;
        }
        printf("%s", line);
    }

    if(close(fd) < 0) {
        perror("close");
        exit(-1);
    }
    return line;
}