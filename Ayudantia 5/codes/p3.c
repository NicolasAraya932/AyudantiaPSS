#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // usleep

#define NH 100

pthread_mutex_t mutex;
pthread_cond_t disponible;

int impresora_libre = 1;

void imprimir(int id)
{
	printf("%d ESTA IMPRIMIENDO\n", id);
	usleep(rand() % 1001);
}

void impresora(int id)
{
	pthread_mutex_lock(&mutex);
	while(!impresora_libre)
	{
		pthread_cond_wait(&disponible, &mutex);
	}

	impresora_libre = 0;

	imprimir(id);

	impresora_libre = 1;

	pthread_cond_signal(&disponible);
	pthread_mutex_unlock(&mutex);
}

void *func(void *arg)
{
	int id = *(int *)arg;
	impresora(id);
	pthread_exit(NULL);
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&disponible, NULL);

	pthread_t hilos[NH];

	int hilos_id[NH];

	for(int i = 0 ; i < NH ; i++)
	{
		hilos_id[i] = i;
		pthread_create(&hilos[i], NULL, func, &hilos_id[i]);
	}

	for(int i = 0 ; i < NH ; i++)
	{
		pthread_join(hilos[i], NULL);
	}

	return 0;
}



