#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* This program demonstrates that the use of the getpid() function.
 *
 * When this was run 100 times on the computer the author is
 * on, only twice did the parent process execute before the
 * child process executed.
 *
 * Note, if you juxtapose two strings, the compiler automatically
 * concatenates the two, e.g., "Hello " "world!"
 *
 * The return value of fork() is actually pid_t ('pid' 't'ype).
 * When it is assigned to 'int pid', if the type is different, there
 * is an implicit cast; however, when we print the return value
 * of getpid(), it is necessary to explicitly cast it as an
 * integer.
 *
 * The type 'pid_t' is defined in the library header <sys/types.h>
 */

int main(void) {
  printf("The process identifier (pid) of the parent process is %d\n",
         (int)getpid());

  int pid = fork();

  if (pid == 0) {
    printf("After the fork, the process identifier (pid) "
           "of the child is %d\n",
           (int)getpid());
    // This is the child process' code
  } else {
    printf("After the fork, the process identifier (pid) "
           "of the parent is still %d\n - fork() returned %d\n",
           (int)getpid(), pid);
    // This is the parent process' code
  }

  return 0;
}
