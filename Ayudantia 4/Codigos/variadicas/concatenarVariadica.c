#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *concatenarVariadica(const char *separator, ...) {
    va_list args;
    va_start(args, separator);

		/* Vemos el primer argumento separador en el while  */
    int size = 0;
    const char *arg;
    while ((arg = va_arg(args, const char *)) != NULL) {
        size += strlen(arg);
        if (separator != NULL) {
            size += strlen(separator);
        }
    }

		/* Correspondiente a la cadena resultante */
    char *result = (char *)malloc(size + 1);
    if (result == NULL) {
        return NULL; // Manejo de errores en la asignación de memoria
    }
    
    // Construir la cadena resultante
    va_start(args, separator); // Reiniciar la lista de argumentos
    char *current = result;
    while ((arg = va_arg(args, const char *)) != NULL) {
        size_t len = strlen(arg);
        memcpy(current, arg, len);
        current += len;
        if (separator != NULL) {
            len = strlen(separator);
            memcpy(current, separator, len);
            current += len;
        }
    }
    *current = '\0';

    va_end(args);

    return result;
}

int main() {
    char *concatenado = concatenarVariadica(" ", "Hola", "desde", "la", "UOH", NULL);
    printf("Concatenado: %s\n", concatenado);
    free(concatenado);

    return 0;
}

