#include "microShell_functions.h"

void clear_screen() {
    printf("\033[2J\033[H");
}
void get_current_working_directory(char* cwd, size_t size) {
    getcwd(cwd, size);
}
void list_directory_contents() {
    pid_t ls = fork();
    if (ls < 0) {
        perror("ERROR: Fork failed.");
        exit(1);
    } else if (ls == 0) {
        execlp("ls", "ls", NULL);
        perror("ERROR: Failed to execute ls.");
        exit(1);
    } else {
        wait(NULL);
    }
}
void create_directory(const char* dir_name) {
    pid_t mkdir = fork();
    if (mkdir < 0) {
        perror("ERROR: Fork failed.");
        exit(1);
    } else if (mkdir == 0) {
        execlp("mkdir", "mkdir", dir_name, NULL);
        perror("ERROR: Failed to execute mkdir.");
        exit(1);
    } else {
        wait(NULL);
    }
}
void remove_directory(const char* dir_name) {
    pid_t rmdir = fork();
    if (rmdir < 0) {
        perror("ERROR: Fork failed.");
        exit(1);
    } else if (rmdir == 0) {
        execlp("rmdir", "rmdir", dir_name, NULL);
        perror("ERROR: Failed to execute rmdir.");
        exit(1);
    } else {
        wait(NULL);
    }
}
void change_directory(const char* path) {
    if (chdir(path) != 0) {
        perror("ERROR: Failed to change directory.");
    }
}
void display_help() {
    printf("Available commands:\n");
    printf("ls - List directory contents\n");
    printf("mkdir <dir_name> - Create a new directory\n");
    printf("rmdir <dir_name> - Remove a directory\n");
    printf("cd <path> - Change directory\n");
    printf("clear - Clear the screen\n");
    printf("help - Display this help message\n");
    printf("exit - Exit the shell\n");
}
void parse_input(char* input, char** args, int* arg_count) {
    *arg_count = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        args[(*arg_count)++] = token;
        token = strtok(NULL, " ");
    }
    args[*arg_count] = NULL;
}