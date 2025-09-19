#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUM_PROCESOS 5
int main() {
  pid_t pid;
  int i;
  for (i = 0; i < NUM_PROCESOS; i++) {
    pid = fork();
    if (pid < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      printf("Soy el hijo #%d, PID: %d, PPID: %d\n", i + 1, getpid(),
             getppid());
      switch (i) {
      case 0:
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl ls");
        exit(EXIT_FAILURE);
      case 1:
        execl("/bin/date", "date", NULL);
        perror("execl date");
        exit(EXIT_FAILURE);
      case 2:
        chdir("..");
        printf("Hijo #%d cambió al directorio padre\n", i + 1);
        break;
      case 3:
        printf("Hijo #%d duerme 2 segundos...\n", i + 1);
        sleep(2);
        break;
      case 4:
        execl("/usr/bin/pwd", "pwd", NULL);
        perror("execl pwd");
        exit(EXIT_FAILURE);
      }
      exit(EXIT_SUCCESS);
    }
  }
  for (i = 0; i < NUM_PROCESOS; i++) {
    wait(NULL);
  }
  printf("Todos los procesos hijos han terminado.\n");
  return 0;
}
