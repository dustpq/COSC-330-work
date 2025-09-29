#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid < 0) {
    /* was not successfully */
  } else if (pid > 0) {
    /* Parent process */
    printf("Parent PID: %i\n", getpid());
  } else {
    /* Child process */
    for (int i = 0; i < 3; i++) {
      // You can see here if we print the child's PID, you can see that each
      // time the number is printed, the PID is displayed, and it is distinct
      // from the parent's PID
      printf("Child PID: %i\n", getpid());
      printf("%i\n", i);
      usleep(2);
    }
    exit(0);
  }
}
