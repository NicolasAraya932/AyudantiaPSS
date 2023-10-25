#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_HILOS 4
#define FILAS 1000
#define COLUMNAS 1000

int matriz[FILAS][COLUMNAS];
int resultados[NUM_HILOS];

void *func(void *arg)
{
	int hilo_id = *(int *)arg;
	int filas_pthread = FILAS / NUM_HILOS;

	int inicio = hilo_id * filas_pthread;
	int fin = (hilo_id == NUM_HILOS - 1) ? FILAS : inicio + filas_pthread;

	int suma_parcial = 0;

	for(int i = inicio; i < fin;i++)
	{
		for(int j = 0;j < COLUMNAS;j++)
		{
			suma_parcial += matriz[i][j];
		}
	}

	resultados[hilo_id] = suma_parcial;
	pthread_exit(NULL);

}

int main()
{
	pthread_t hilos[NUM_HILOS];
	int hilos_id[NUM_HILOS];

	for(int i = 0; i < FILAS;i++)
	{
		for(int j = 0; j < COLUMNAS ; j++)
		{
			matriz[i][j] = rand() % 50;
		}
	}

	for(int i = 0; i < NUM_HILOS;i++)
	{
		hilos_id[i] = i;
		pthread_create(&hilos[i], NULL, func, &hilos_id[i]);
	}

	for(int i = 0;i < NUM_HILOS;i++)
	{
		pthread_join(hilos[i], NULL);
	}


	int suma_t = 0;

	for(int i = 0; i < NUM_HILOS;i++)
	{
		suma_t += resultados[i];
	}

	printf("%d\n", suma_t);

	return 0;
}
