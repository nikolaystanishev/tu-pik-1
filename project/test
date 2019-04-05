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
              
              } else {
               
                   read_file(input_file);
              }

        if () {} else {} if () {}
                       return 0;

  }
   

a