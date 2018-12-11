#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>


int get_file_descriptor(const char*, int, int);
void write_int(int, int);
char* read_line(int);
void process_file(const char*, const char*);
int get_num_of_words(char*);
char* str_add_char(char*, char, unsigned long);
int find_num_of_needle(char*, char*);
int is_str_ends_with(char*);

int main() {
    if(write(STDOUT_FILENO, "Insert input file (for read from standard input enter stdin): ", 63) < 0) {
        perror("write");
        exit(-1);
    }
    char *input_file = read_line(STDIN_FILENO);
    if(input_file == NULL) {
        exit(0);
    }
    if(!is_str_ends_with(input_file)) {
        if(write(STDOUT_FILENO, "Input file must have '.c' extension!", 38) < 0) {
            perror("write");
            exit(-1);
        }
        exit(-1);
    }

    if(write(STDOUT_FILENO, "Insert output file (for read from standard output enter stdout): ", 66) < 0) {
        perror("write");
        exit(-1);
    }
    char *output_file = read_line(STDIN_FILENO);
    if(output_file == NULL) {
        exit(0);
    }

    process_file(input_file, output_file);

    free(input_file);
    free(output_file);

    return 0;
}

int is_str_ends_with(char* string) {
    if (strcmp(string, "stdin") == 0) {
        return 1;
    }

    string = strrchr(string, '.');
    if (string != NULL) {
        return !(strcmp(string, ".c"));
    }

    return 0;
}

int get_file_descriptor(const char* file_name, int mode, int default_fd) {
    int fd = default_fd;

    if (!((strcmp(file_name, "stdin") == 0) || (strcmp(file_name, "stdout") == 0))) {
        fd = open(file_name, mode);
        if(fd < 0) {
            perror("open");
            exit(-1);
        }
    }

    return fd;
}

void write_int(int fd, int integer) {
    int digits_num = (int)log10(integer) + 1;
    if (integer == 0) {
        digits_num = 1;
    }

    char *str_integer = (char*)calloc(digits_num + 1, sizeof(char));
    if (str_integer == NULL) {
        perror("calloc");
        exit(-1);
    }

    for (int i = digits_num - 1; i >= 0; i--, integer /= 10) {
        str_integer[i] = (integer % 10) + '0';
    }

    str_integer[digits_num] = '\0';

    if (write(fd, str_integer, digits_num) < 0) {
        perror("write");
        exit(-1);
    }

    free(str_integer);
}

char* str_add_char(char* str, char c, unsigned long str_size) {
    str = (char*)realloc(str, str_size);
    if(str == NULL) {
        perror("realloc");
        exit(-1);
    }
    str[str_size - 1] = c;
    return str;
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

        if(buff[0] == '\n') {
            if (cmdlineSize == 0) {
                cmdlineSize++;
                cmdline = str_add_char(cmdline, '\n', cmdlineSize);
            }

            cmdlineSize++;
            cmdline = str_add_char(cmdline, '\0', cmdlineSize);

            return cmdline;
        } else {
            cmdlineSize++;
            cmdline = str_add_char(cmdline, buff[0], cmdlineSize);
        }
    }

    if (cmdlineSize != 0) {
        cmdlineSize++;
        cmdline = str_add_char(cmdline, '\0', cmdlineSize);
        return cmdline;
    }

    return NULL;
}

int find_num_of_needle(char* line, char* needle) {
    int num_of_needle = 0;

    char* haystack = (char*)calloc(strlen(line) + 1, sizeof(char));
    if (haystack == NULL) {
        perror("calloc");
        exit(-1);
    }
    strcpy(haystack, line);

    while(1) {
        haystack = strstr(haystack, needle);
        if(haystack == NULL) {
            break;
        }
        num_of_needle++;
        haystack += strlen(needle);
    }

    return num_of_needle;
}

void process_file(const char* input_file_name, const char* output_file_name) {
    int in_fd = get_file_descriptor(input_file_name, O_RDONLY, STDIN_FILENO);
    int out_fd = get_file_descriptor(output_file_name, O_WRONLY, STDOUT_FILENO);

    int open_brackets = 0;
    int blocks = 0;
    int if_num = 0, else_num = 0;

    while(1) {
        char *line = read_line(in_fd);
        if (line == NULL) {
            break;
        }

        if_num += find_num_of_needle(line, "if");
        else_num += find_num_of_needle(line, "else");

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '{') {
                open_brackets++;
            } else if (line[i] == '}') {
                open_brackets--;
                if (open_brackets < 0) {
                    break;
                }
                blocks++;
            }
        }

        free(line);
    }

    if (open_brackets != 0) {
        if(write(out_fd, "Unclosed blocks!", 17) < 0) {
            perror("write");
            exit(-1);
        }
    } else {
        if(write(out_fd, "blocks = ", 10) < 0) {
            perror("write");
            exit(-1);
        }
        write_int(out_fd, blocks);
    }

    if(write(out_fd, "\n", 2) < 0) {
        perror("write");
        exit(-1);
    }

    if(write(out_fd, "if conditions = ", 17) < 0) {
        perror("write");
        exit(-1);
    }
    write_int(out_fd, if_num - else_num);

    if(write(out_fd, "\n", 2) < 0) {
        perror("write");
        exit(-1);
    }

    if(write(out_fd, "if/else conditions = ", 22) < 0) {
        perror("write");
        exit(-1);
    }
    write_int(out_fd, else_num);

    if(write(out_fd, "\n", 2) < 0) {
        perror("write");
        exit(-1);
    }

    if(close(in_fd) < 0) {
        perror("close");
        exit(-1);
    }
    if(close(out_fd) < 0) {
        perror("close");
        exit(-1);
    }
}
