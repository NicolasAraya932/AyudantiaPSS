#include <stdlib.h>
#include "p1.c"

#define QUEUESIZE 10

typedef int Info;

semaphore mutex;
semaphore cola;

int xD = 0; // en espera

Info *info = NULL;

void difundir(void *pinfo) {
    semaphore_wait(&mutex);
    int bloqueados = xD;
    xD = 0;
    semaphore_post(&mutex);
    info = (Info *)pinfo;
    printf("%d\n", *info);
    while(bloqueados--)
    {
        semaphore_post(&cola);
    }
}
void *esperar() {
    semaphore_wait(&mutex);
    xD++;
    semaphore_post(&mutex);
    semaphore_wait(&cola);
    return info;
}
int main()
{
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
