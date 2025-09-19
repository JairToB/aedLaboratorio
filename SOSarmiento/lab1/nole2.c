#include <stdio.h>
#include <unistd.h> // Para fork() y getpid()
#include <stdlib.h> // Para exit()
#include <sys/wait.h> // Para wait()

int main() {
    pid_t pid;
    int i;

    // Bucle para crear dos procesos iniciales (padre y un hijo)
    for (i = 0; i < 2; i++) {
        pid = fork(); // Primera llamada a fork()

        if (pid < 0) { // Error
            perror("Error al crear el proceso");
            exit(1);
        } else if (pid == 0) { // Proceso hijo
            printf("Soy el proceso hijo (PID: %d), hijo del proceso padre (PPID: %d)\n", getpid(), getppid());
            // Cada hijo ahora creará su propio hijo
            if (i == 0) { // Si es el primer hijo que llama a fork
                pid = fork(); // Segunda llamada a fork()
                if (pid < 0) {
                    perror("Error al crear el nieto");
                    exit(1);
                } else if (pid == 0) { // Nuevo nieto
                    printf("Soy un nieto (PID: %d), hijo de %d\n", getpid(), getppid());
                    // Este nieto se puede considerar el cuarto proceso hijo
                    exit(0); // Terminar el nieto
                } else { // El primer hijo vuelve a ser padre
                    printf("El primer hijo (PID: %d) creó un nieto (PID: %d)\n", getpid(), pid);
                    // El primer hijo espera a su hijo
                    wait(NULL);
                    exit(0); // El primer hijo termina
                }
            } else { // Si es el segundo hijo que llama a fork
                pid = fork(); // Tercera llamada a fork()
                if (pid < 0) {
                    perror("Error al crear el nieto");
                    exit(1);
                } else if (pid == 0) { // Nuevo nieto
                    printf("Soy otro nieto (PID: %d), hijo de %d\n", getpid(), getppid());
                    // Este es el cuarto proceso hijo
                    exit(0); // Terminar este nieto
                } else { // El segundo hijo vuelve a ser padre
                    printf("El segundo hijo (PID: %d) creó un nieto (PID: %d)\n", getpid(), pid);
                    // El segundo hijo espera a su hijo
                    wait(NULL);
                    exit(0); // El segundo hijo termina
                }
            }
            exit(0); // El primer o segundo hijo termina después de crear su nieto
        } else { // Proceso padre
            printf("Soy el proceso padre (PID: %d), creé al hijo (PID: %d)\n", getpid(), pid);
            // El padre espera a su hijo (y a su respectivo nieto)
            wait(NULL);
        }
    }

    printf("Todos los procesos han terminado. Padre (PID: %d)\n", getpid());
    return 0;
}
