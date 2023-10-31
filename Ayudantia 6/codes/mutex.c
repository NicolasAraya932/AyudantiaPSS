#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

int counter = 0;

void count(void *arg)
{
	pthread_mutex_lock(&mutex);
	counter = (counter + 1) % 5;
	printf("%d\n", counter);
	pthread_mutex_unlock(&mutex);
}

int main()
{

	pthread_mutex_init(&mutex, NULL);

	pthread_t thread[5];

	for(int x = 0; x < 20 ; x++)
	{
		for(int i = 0;i < 5;i++)
		{
			pthread_create(&thread[i], NULL,(void *) count , NULL);
		}

		for(int i = 0;i < 5;i++)
		{
			pthread_join(thread[i], NULL);
		}
	}

	return 0;
}
