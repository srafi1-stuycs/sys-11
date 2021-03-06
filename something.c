#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
  char ** parse_args(char* line) {
  char ** args = (char **) malloc(5*sizeof(char*));
  int index = 0;
  while (line) {
  args[index] = strsep(&line, " ");
  index += 1;
  }
  return args;
  }
*/
char ** parse_args( char * line ){
  char ** args = (char **) malloc(sizeof(char) * 6);
  int count;
  for(count = 0; count < 7; count ++){
    args[count] = strsep(&line, " ");
  }
  return args;
}

void printarr(char** args) {
  int index = 0;
  int i;
  printf("[");
  for (i = 0; i < 5; i++) {
    printf("%s, ", args[i]);
  }
  printf("]\n");
}

int main() {
  char line1[256] = "ls -al .";
  printf("%s into: ", line1);
  char ** line1_args = parse_args(line1);
  printarr(line1_args);

  char line2[256] = "ls -a -l . asdf";
  printf("%s into: ", line2);
  char ** line2_args = parse_args(line2);
  printarr(line2_args);
  printf("\n");

  printf("Running with results from: ls -al\n");
  execvp("ls", line2_args);

  return 0;
}
