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
    if (pid < 0) { // Error al crear el proceso
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) { // Este es el proceso hijo
      printf("Soy el hijo #%d, PID: %d, PPID (padre):%d\n", i + 1, getpid(), getppid());
      exit(EXIT_SUCCESS); // Salimos del hijo para no crear más hijos desde él
    }
    // El padre sigue el bucle para crear más hijos
  }
  // Esperar a todos los hijos
  for (i = 0; i < NUM_PROCESOS; i++) {
    wait(NULL);
  }
  printf("Todos los procesos hijos han terminado.\n");
  return 0;
}
