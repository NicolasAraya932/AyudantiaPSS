#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t child;

    child = fork();

    switch (child)
    {
    case -1:
        perror("ERROR");
        exit(0)
    case 0:
        execlp("ps", "ps", "-ax", NULL);
        break;
    default:
        break;
    }

    waitpid(child,(int *) 0, NULL);

    return 0;
}