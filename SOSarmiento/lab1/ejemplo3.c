#include <stdio.h>
#include <unistd.h>
int main() {
  int pid;
  printf("The main program process ID is %d\n", (int)getpid());
  for (int i = 0; i < 1; ++i) {
    pid = fork();
    if (pid != 0) {
      printf("This is the parent process, with id %d \n", (int)getpid());
      printf("The child process ID is %d\n", pid);
    } else {
      printf("This is the child process, with id %d\n", (int)getpid());
    }
  }
  return 0;
}
