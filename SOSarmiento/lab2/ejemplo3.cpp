#include <iostream>
#include <unistd.h>
int main() {
  pid_t pid = fork();
  if (pid == 0) {
    std::cout << "Hijo (PID:" << getpid() << ") termina inmediatamente.\n";
    return 0;
  } else {
    std::cout << "Padre(PID: " << getpid() << ")duerme por 20 segundos.\n";
    sleep(20);
    std::cout << "Padre despierta.\n";
  }
  return 0;
}
