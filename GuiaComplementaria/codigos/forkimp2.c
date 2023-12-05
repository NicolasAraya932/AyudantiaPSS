#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t child;

    child = fork();

    if(child == -1) {
        perror("ERROR");
        exit(0)
    }
    else if(child == 0){
        execlp("ps", "ps", "-ax", NULL);
    }
    else{
        printf("Soy el padre\n");
    }

    waitpid(child,(int *) 0, NULL);

    return 0;
}