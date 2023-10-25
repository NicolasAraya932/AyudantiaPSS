#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_COLA_SIZE 10
#define NUM_PRODUCTORES 4
#define NUM_CONSUMIDORES 3

pthread_mutex_t mutex;
pthread_cond_t not_empty;
pthread_cond_t not_full;

int cola[MAX_COLA_SIZE];
int front = 0, rear = 0;
int itemCount = 0;



void encola(int item)
{
	cola[rear] = item;
	rear = (rear + 1) % MAX_COLA_SIZE;
	itemCount++;
}

int fueraCola()
{
	int item = cola[front];
	front = (front + 1) % MAX_COLA_SIZE;
	itemCount--;
	return item;
}

void *productor(void *arg)
{
	int item;
	for( int i = 0; i < 10;i++)
	{
		item = rand() % 100;

		pthread_mutex_lock(&mutex);

		while(itemCount == MAX_COLA_SIZE)
		{
			pthread_cond_wait(&not_full, &mutex);
		}

		encola(item);

		printf("PRODUCTOR %d PRODUJO %d\n",*((int *)arg), item);

		pthread_cond_signal(&not_empty);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

void *consumidor(void *arg)
{
	int item;
	while (1)
	{
		pthread_mutex_lock(&mutex);

		while(itemCount == 0)
		{
			pthread_cond_wait(&not_empty, &mutex);
		}

		item = fueraCola();

		printf("CONSUMIDOR %d CONSUMIO %d\n", *((int *)arg), item);

		pthread_cond_signal(&not_full);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&not_empty,NULL);
	pthread_cond_init(&not_full,NULL);

	pthread_t productor_hilos[NUM_PRODUCTORES];
	pthread_t consumidor_hilos[NUM_CONSUMIDORES];

	int productor_id[NUM_PRODUCTORES];
	int consumidor_id[NUM_CONSUMIDORES];

	for( int i = 0; i < NUM_PRODUCTORES ; i ++)
	{
		productor_id[i] = i;
		pthread_create(&productor_hilos[i], NULL, productor, &productor_id[i]);
	}

	for( int i = 0; i < NUM_PRODUCTORES ; i ++)
	{
		consumidor_id[i] = i;
		pthread_create(&consumidor_hilos[i], NULL, consumidor, &consumidor_id[i]);
	}

	for( int i = 0 ; i < NUM_PRODUCTORES ; i++)
	{
		pthread_join(productor_hilos[i], NULL);
	}

	return 0;
}




