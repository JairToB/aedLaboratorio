#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main() {
  pid_t pid = fork();
  if (pid == 0) {
    std::cout << "Hijo ejecutará 'ls -l'...\n";
    execl("/bin/ls", "ls", "-l", NULL);
    std::cerr << "Error al ejecutar exec()\n";
  } else {
    wait(NULL);
    std::cout << "Padre: hijo ha terminado.\n";
  }
  return 0;
}
