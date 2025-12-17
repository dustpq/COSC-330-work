// The goal is to make a micro shell.
// Include ability to run "ls", "mkdir", and maybe a few more later on.
// The idea is to make a rip off BASH shell

#include "microShell_functions.h"
#include "oct29/oct_29_lib.h"

int main() {
  printf("\033[2J\033[H");
  char cwd[PATH_MAX];
  getcwd(cwd, sizeof(cwd));

  for (;;) {
    printf("user@CShell %s> ", cwd);

    char input[256];
    char command[50], argument [200];

    if (fgets(input, sizeof(input), stdin) == NULL) {
      perror("ERROR: Failed to read input.");
      exit(1);
    }

    if (sscanf(input, "%49s %199[^\n]", command, argument) < 1) {
    printf("CShell: Invalid input.\n");
    continue;
    }

    if (strcmp(command, "ls") == 0) {
    list_directory_contents();

    } else if (strcmp(command, "mkdir") == 0) {
        if (strlen(argument) == 0) {
            printf("CShell: mkdir requires a directory name\n");
            continue;
        }
        create_directory(argument);

    } else if (strcmp(command, "rmdir") == 0) {
        if (strlen(argument) == 0) {
            printf("CShell: rmdir requires a directory name\n");
            continue;
        }
        remove_directory(argument);

    } else if (strcmp(command, "cd") == 0) {
        if (strlen(argument) == 0) {
            printf("CShell: cd requires a path\n");
            continue;
        }
        change_directory(argument);
        getcwd(cwd, sizeof(cwd));

    } else if (strcmp(command, "touch") == 0) {
        if (strlen(argument) == 0) {
            printf("CShell: touch requires a file name\n");
            continue;
        }
        touch_file(argument);

    } else if (strcmp(command, "rm") == 0) {
        if (strlen(argument) == 0) {
            printf("CShell: rm requires a file name\n");
            continue;
        }
        remove_file(argument);

    } else if (strcmp(command, "clear") == 0) {
        clear_screen();

    } else if (strcmp(command, "help") == 0) {
        display_help();

    } else if (strcmp(command, "lib_hello") == 0) {
        hello();

    } else if (strcmp(command, "exit") == 0) {
        printf("Process finished.\n");
        exit(0);

    } else {
        printf("CShell: command not found: %s\n", command);
    }
  };

  return 0;
};
