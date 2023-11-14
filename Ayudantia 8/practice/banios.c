#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t _damas;
pthread_cond_t _varones;

int damas=0; int varones=0;

void entraVaron()
{
	pthread_mutex_lock(&mutex);
	while(damas > 0)
	{
		pthread_cond_wait(&_varones, &mutex);
	}
	printf("Entra Varon");
	varones++;
	pthread_mutex_unlock(&mutex);

	pthread_mutex_lock(&mutex);
	printf("Sale Varon%d\n", varones);
	varones--;
	pthread_cond_broadcast(&_damas);
	pthread_mutex_unlock(&mutex);
}

void entraDamas()
{
	pthread_mutex_lock(&mutex);
	while(varones > 0)
	{
		pthread_cond_wait(&_damas, &mutex);
	}
	printf("Entra Dama");
	damas++;
	pthread_mutex_unlock(&mutex);

	pthread_mutex_lock(&mutex);
	printf("Sale Dama%d\n", damas);
	damas--;
	pthread_cond_broadcast(&_varones);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t damas_t[4];
	pthread_t varones_t[4];


	for(int i = 0; i < 4 ; i++)
	{
		pthread_create(&varones_t[i], NULL, (void *)entraVaron, NULL);
	}
	for(int i = 0; i < 4 ; i++)
	{
		pthread_create(&damas_t[i], NULL, (void *)entraDamas, NULL);
	}
	for(int i = 0; i < 4 ; i++)
	{
		pthread_join(damas_t[i],NULL);
	}
	for(int i = 0; i < 4 ; i++)
	{
		pthread_join(varones_t[i],NULL);
	}

	return 0;
}
