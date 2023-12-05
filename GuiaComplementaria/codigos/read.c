#include <unistd.h>
#include <stdlib.h>

int main()
{
    char buffer[128];
    int nread;

    /*Recordar que size_t es un entero*/
    nread = read(0, buffer, 128);
    if (nread == -1) 
        write(2, "ERROR EN WRITE\n", 15);
    /*Usamos nread como tamanno de buffer*/
    if ((write(1, buffer, nread)) != nread)
        write(2, "ERROR EN WRITE\n", 15);

    exit(0);
}