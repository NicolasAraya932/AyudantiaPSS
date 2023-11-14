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
	varones++;
	pthread_cond_broadcast(&_damas);
	pthread_mutex_unlock(&mutex);
}

void salirVaron()
{
	pthread_mutex_lock(&mutex);
	varones--;
	pthread_mutex_unlock(&mutex);
}


void entraDamas()
{
	pthread_mutex_lock(&mutex);
	while(varones > 0)
	{
		pthread_cond_wait(&_damas, &mutex);
	}
	damas++;
	pthread_cond_broadcast(&_varones);
	pthread_mutex_unlock(&mutex);
}

void salirDamas()
{
	pthread_mutex_lock(&mutex);
	damas--;
	pthread_mutex_unlock(&mutex);
}


int main()
{
	pthread_t baño[5];


	return 0;
}
