#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PROCESOS 3

int main() {
  pid_t pid, wpid;
  int status;
  int i;
  for (i = 0; i < NUM_PROCESOS; i++) {
    pid = fork();
    if (pid < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      printf("Hijo #%d (PID: %d) iniciado.\n", i + 1, getpid());
      sleep(2 + i);
      printf("Hijo #%d (PID: %d) termina.\n", i + 1, getpid());
      exit(100 + i);
    }
  }
  while ((wpid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("Padre: hijo con PID %d terminó con código %d.\n", wpid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Padre: hijo con PID %d terminó por señal %d.\n", wpid, WTERMSIG(status));
    }
  }

  printf("Todos los hijos terminaron.\n");
  return 0;
}
