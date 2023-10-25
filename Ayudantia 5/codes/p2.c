#include <stdio.h>
#include <pthread.h>

#define NH 6

pthread_mutex_t mutex;

int shared = 0;

void *func(void *arg)
{
	for(int i = 0; i < 1000 ; i++)
	{
		pthread_mutex_lock(&mutex);
		shared++;
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);
}


int main()
{
	pthread_t hilos[NH];
	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < NH ; i++)
	{
		pthread_create(&hilos[i], NULL, func, NULL);
	}

	for(int i = 0; i < NH ; i++)
	{
		pthread_join(hilos[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	printf("%d\n", shared);

	return 0;

}
