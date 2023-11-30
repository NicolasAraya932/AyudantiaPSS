#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define THREADS 2

pthread_mutex_t mutex;


void printArr(int arr[], int size)
{
	for(int i = 0; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;

	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i = 0; i < n1 ; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2 ; j++)
		R[j] = arr[m + 1 + j];

	j = 0;
	i = 0;
	k = l; // index
	
	while ( i < n1 && j < n2 )
	{
		pthread_mutex_lock(&mutex);
		if ( L[i] <= R[j] )
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
		pthread_mutex_unlock(&mutex);
	}

	while ( i < n1 )
	{
		pthread_mutex_lock(&mutex);
		arr[k] = L[i];
		i++;
		k++;
		pthread_mutex_unlock(&mutex);
	}

	while ( j < n2 )
	{
		pthread_mutex_lock(&mutex);
		arr[k] = R[j];
		j++;
		k++;
		pthread_mutex_unlock(&mutex);
	}


}

void mergeSort(int arr[], int l, int r)
{
	if(l > r)
	{ 
		int m = l + (r - 1) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
		printArr(arr, sizeof(&arr)/sizeof(arr[0]));
	}
}

void mSortThread(void *arg[])
{
	int *arr = (int *)arg;

	mergeSort(arr, 0, sizeof(&arr)/sizeof(arr[0]) - 1);

	pthread_exit(NULL);
}


int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[THREADS];

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int m = arr_size / THREADS;

    for (int i = 0; i < THREADS; i++)
    {
        int inicio = m * i;
        int fin = (i == THREADS - 1) ? arr_size - 1 : m * (i + 1) - 1;

        pthread_create(&threads[i], NULL, (void *)mSortThread, (void *)(arr + inicio));
    }

    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printArr(arr, arr_size);

    return 0;
}

