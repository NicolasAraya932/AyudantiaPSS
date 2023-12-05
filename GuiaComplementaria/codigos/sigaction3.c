#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct sigaction act;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGNAL, &act, 0);
}