#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFFERSIZE 20
#define MAXNODE 4
#define NTHREADS 4

pthread_mutex_t mutex;
pthread_cond_t makeNode;
pthread_cond_t freeNode;

int buf_size  = 0;
int total_node = 0;

typedef struct node {
	char data[BUFFERSIZE]; 
	struct node *next;
} Node;

void freeLIST(Node *list)
{
	while(list != NULL)
	{
		Node *aux = list;
		list = list->next;
		free(aux->data);
		free(aux);
	}
}

void addNode(Node *list, Node *node)
{
	while(list->next != NULL)
	{
		list = list->next;
	}
	list->next = node;
}

void producer(void *arg)
{
	// Leemos y guardamos
	Node *head = (Node *)arg;
	char string[BUFFERSIZE];
	int c;

	while((c=getchar()) != EOF)
	{
		pthread_mutex_lock(&mutex);
		while(total_node == MAXNODE)
		{
			pthread_cond_wait(&makeNode, &mutex);
		}
		string[buf_size] = c;

		if(++buf_size == BUFFERSIZE)
		{
			Node *node = (Node *) malloc(sizeof(Node));
			if(node != NULL)
			{
				memcpy(node->data, string, BUFFERSIZE);
				node->next = NULL;
				addNode(head, node);
				buf_size = 0;
			}
		}
		pthread_cond_signal(&freeNode);
		pthread_mutex_unlock(&mutex);
	}
}

void consumer(void *arg)
{
	// Procesamos y liberamos
	Node *head = (Node *)arg;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(total_node == 0)
		{
			pthread_cond_wait(&freeNode, &mutex);
		}
		pthread_cond_signal(&makeNode);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t producer_t[NTHREADS], consumer_t[NTHREADS];

	Node *head = (Node *)malloc(sizeof(Node));

	for (int i = 0; i < NTHREADS; i++) {
			pthread_create(&producer_t[i], NULL, (void*)producer, head);
	}

	for (int i = 0; i < NTHREADS; i++) {
			pthread_create(&consumer_t[i], NULL, (void*)consumer, head);
	}

	for (int i = 0; i < NTHREADS; i++) {
			pthread_join(producer_t[i], NULL);
	}

	for (int i = 0; i < NTHREADS; i++) {
			pthread_join(consumer_t[i], NULL);
	}

	freeLIST(head);

	return 0;
}

