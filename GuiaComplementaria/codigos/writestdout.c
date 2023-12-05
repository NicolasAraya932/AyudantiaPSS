#include <unistd.h>
#include <stdlib.h>

int main()
{
    if((write(1, "Hola Mundo\n", 11) != 11))
        write(2, "ERROR EN WRITE\n", 15);
    exit(0);
}