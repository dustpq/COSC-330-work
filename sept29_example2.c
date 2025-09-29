#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid < 0) {
    /* was not successfully */
  } else if (pid > 0) {
    /* Parent process */
  } else {
    /* Child process */
    for (int i = 0; i < 5; i++) {
      fork();
      printf("%i\n", i);
      usleep(1000);
    }
    exit(0);
  }
}
