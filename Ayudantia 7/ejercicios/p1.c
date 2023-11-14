#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
	int value;
	pthread_mutex_t m;
	pthread_cond_t c;
} semaphore;

void semaphore_init(semaphore *s, int value)
{
	s->value=value;
	pthread_mutex_init(&s->m, NULL);
	pthread_cond_init(&s->c, NULL);
}

void semaphore_destroy(semaphore *s)
{
	pthread_mutex_destroy(&s->m);
	pthread_cond_destroy(&s->c);
}

void semaphore_wait(semaphore *s)
{
	pthread_mutex_lock(&s->m);
	while(s->value == 0)
	{
		pthread_cond_wait(&s->c, &s->m);
	}
	s->value--;
	pthread_mutex_unlock(&s->m);
}

void semaphore_post(semaphore *s)
{
	pthread_mutex_lock(&s->m);
	s->value++;
	pthread_cond_broadcast(&s->c);
	pthread_mutex_unlock(&s->m);
}
