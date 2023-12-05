#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig)
{
    alarm_fired = 1;
}

int main()
{
    pid_t pid;

    printf("alarm application starting\n");

    pid = fork();
    switch (pid)
    {
    case -1:
        /* Error al hacer fork */
        perror("fork failed");
        exit(1);
    case 0:
        /* Proceso hijo */
        sleep(5); //Espera 5 segundos
        kill(getppid(), SIGALRM); //Envia la sennal SIGALRM al proceso padre
        exit(0);
    }

    /* El proceso padre configura la captura de la sennal SIGALRM con una llamada a signal y luego espera la sennal */
    printf("waiting for alarm to go off\n");
    signal(SIGALRM, ding);

    pause(); // proceso padre se bloquea hasta que reciba una sennal

    if (alarm_fired)
        printf("Ding!\n");

    printf("done\n");

    return 0;
}
