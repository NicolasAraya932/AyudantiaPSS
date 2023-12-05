#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    /*Se declaran las variables que representan
     *el PID una vez realizado fork
     */
    pid_t awkpid, lesspid, pid;

    int status = 0;
    /* File descriptors */
    int file_descriptors[2];

    /*En caso de error*/
    if(pipe(file_descriptors) < 0){
        perror("ERROR PIPE\n");
        exit(1);
    }

    /* Se evaluan los casos de manera individual */
    awkpid = fork();
    if(awkpid < 0){
        perror("ERROR FORK\n");
        exit(1);
    }
    if(awkpid == 0){
        /* Para evitar una comunicacion paralela entre los
         * procesos se cierra el descriptor que no se utilizara
         */
        close(file_descriptors[0]);

        /* Se asigna la escritura a la salida estandar */
        close(1);
        dup(file_descriptors[1]);
        /* Una vez duplicado tenemos la informacion necesaria */
        
        close(file_descriptors[1]);

        chdir("/");
        execl("/bin/awk", "awk", "'{print}' read.c", 0);

    }


    lesspid = fork();

    if(lesspid < 0) {
        fprintf(stderr, "fallo el fork\n");
        exit(1);
    }   
    if(lesspid == 0) { /* more */
        /* Cerrar el extremo write del pipe que no voy a usar */
        close(fds[1]);
        /* Asigno: 0 (stdin) = fds[0] (lado de lectura del pipe) */
        close(0); dup(fds[0]);
        /* Cerrar la copia que me queda sobre el pipe o no tendre' EOF*/
        close(fds[0]);  
        execl("/bin/less.txt", "less", 0);
        fprintf(stderr, "Fallo el exec\n");
        exit(-1);
    }
    /* Como padre comun, cierro el pipe, ambos extremos (yo no louso) */
    close(fds[0]); close(fds[1]);

    if(waitpid(morepid, &status, 0) != morepid) {
        fprintf(stderr, "fallo el wait2\n");
        perror("wait2");
        exit(-1);
    }
    if(waitpid(lspid, &status, 0) != lspid) {
        perror("wait1");
        exit(-1);
    }
    
}