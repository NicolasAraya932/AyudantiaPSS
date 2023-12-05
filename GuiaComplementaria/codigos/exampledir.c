#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    // Declarar un puntero a directorio
    DIR *dp;

    // Estructura dirent para almacenar la informacion de cada entrada de directorio
    struct dirent *entry;

    // Asignar un directorio a dp mediante opendir
    dp = opendir(".");  // Abre el directorio actual

    if (dp == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    // Realizar una lectura de los directorios mediante readdir
    while ((entry = readdir(dp)) != NULL) {
        // Ignorar las entradas "." y ".." que representan el directorio actual y el directorio padre
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }

    // Cerrar el directorio
    closedir(dp);

    return 0;
}