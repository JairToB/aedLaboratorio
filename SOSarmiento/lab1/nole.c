#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int num_hijos = 3;

    printf("Proceso padre: PID=%d, PPID=%d\n", getpid(), getppid());

    for (int i = 0; i < num_hijos; i++) {
        pid = fork(); // Llamada a fork()

        if (pid < 0) { // Error al crear el proceso
            perror("Error en fork");
            return 1;
        } else if (pid == 0) { // Es un proceso hijo
            printf("Proceso hijo %d: PID=%d, PPID=%d\n", i, getpid(), getppid());
            // Aquí el hijo realiza sus tareas
            return 0; // El hijo termina su ejecución
        }
        // Si pid > 0, es el padre y continúa con la siguiente iteración o sale del bucle
    }
    printf("Proceso padre: Todos los hijos han sido creados.\n");
    return 0;
}
