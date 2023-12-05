#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running System\n");
    system("ps -ax");
    printf("DONE\n");

    exit(0);
}