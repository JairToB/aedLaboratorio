#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main() {
  pid_t pid = fork();
  if (pid == 0) {
    // Proceso hijo
    execl("/bin/ls", "ls", "-l", NULL);
  } else {
    // Proceso padre
    wait(NULL); // Espera a que el hijo termine
  }
  return 0;
}
