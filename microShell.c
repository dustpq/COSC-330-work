// The goal is to make a micro shell.
// Include ability to run "ls", "mkdir", and maybe a few more later on.
// The idea is to make a rip off BASH shell

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  printf("\033[2J\033[H");
  char cwd[PATH_MAX];
  getcwd(cwd, sizeof(cwd));

  for (;;) {
    printf("user@CShell %s> ", cwd);

    char input[10];
    int scan_result = scanf("%s", &input[0]);

    if (strcmp(input, "ls") == 0) {
      pid_t ls = fork();

      if (ls < 0) {
        // Fork failed, exiting program
        perror("ERROR: Fork failed.");
        exit(1);
      } else if (ls == 0) {
        // Child process continues here
        execlp("ls", "ls,", NULL);
        // If exec fails, print error
        perror("ERROR: Failed to execute ls.");
        exit(1);
      } else {
        // Parent process continues here
        wait(NULL);
      }

    } else if (strcmp(input, "mkdir") == 0) {
      pid_t mkdir = fork();

      if (mkdir < 0) {
        // Fork failed, exiting program
        perror("ERROR: Fork failed.");
        exit(1);
      } else if (mkdir == 0) {
        // Child process continues here
        execlp("mkdir", "mkdir,", "new_dir", NULL);
        // If exec fails, print error
        perror("ERROR: Failed to execute mkdir.");
        exit(1);
      } else {
        // Parent process continues here
        wait(NULL);
      }

    } else if (strcmp(input, "help") == 0) {
      printf("Availible commands:\nls\nmkdir\nhelp\n");

    } else if (strcmp(input, "exit") == 0) {
      printf("Process finished.\n");
      exit(0);

    } else {
      printf("CShell: command not found: %s\n", &input[0]);
    }
  };

  return 0;
};
