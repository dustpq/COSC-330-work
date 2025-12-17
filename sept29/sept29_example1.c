// execDemo.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  // A null terminated array of character
  // pointers
  char *args[] = {"./sept29_example1_hello", NULL};
  // changed ./hello to ./sept29_example1_hello.c so it will actually exec the
  // file
  execvp(args[0], args);

  /*All statements are ignored after execvp() call as this whole
  process(execDemo.c) is replaced by another process (EXEC.c)
  */
  printf("Ending-----\n");

  return 0;
}
