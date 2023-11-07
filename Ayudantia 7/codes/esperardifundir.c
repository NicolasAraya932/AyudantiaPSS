#include <stdlib.h>
#include "sem.c"

#define QUEUESIZE 1

typedef int Info;

semaphore cola; // cola de tareas en esperar()
semaphore mutex; // evita datarace en esperando

int esperando = 0; // numero de threads pendientes a esperar()

Info *info = NULL;

void difundir(void *pinfo) {

    semaphore_wait(&mutex);
    int bloqueados = esperando; // numero de threads en la cola
    esperando = 0; // resetea contador de threads
    semaphore_post(&mutex);
    info = (Info *)pinfo;
    printf("%d\n", *info);
    while (bloqueados > 0)// pone tickets para threads en esperar()
        semaphore_post(&cola);
}

void *esperar() {

    semaphore_wait(&mutex);
    esperando++; // se incrementa el numero de threads en esperar()
    printf("%d\n", esperando);
    semaphore_post(&mutex); 
    semaphore_wait(&cola); // se encola para recibir la información de difundir()
    return info;
}

int main() {
    semaphore_init(&cola, 0);
    semaphore_init(&mutex, QUEUESIZE);

    pthread_t threads_m[QUEUESIZE];
    pthread_t threads_c[QUEUESIZE];

    for(int i = 0; i < QUEUESIZE; i++)
    {
        pthread_create(&threads_c[i], NULL, (void *)esperar, NULL);
    }

    for(int i = 0; i < QUEUESIZE; i++)
    {
        
        Info data = rand() % 42;
        pthread_create(&threads_m[i], NULL, (void *)difundir, (void *)&data);
    }

    for(int i = 0;i < QUEUESIZE; i++)
    {
        pthread_join(threads_c[i], NULL);
    }
        
    // Clean up resources
    semaphore_destroy(&cola);
    semaphore_destroy(&mutex);

    return 0;
}
