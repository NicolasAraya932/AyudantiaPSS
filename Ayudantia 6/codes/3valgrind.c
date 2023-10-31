#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *array = malloc(sizeof(array)*10);

	for(int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
	}

	int randNum = rand() %  10;

	printf("array[%d]: %d\n", randNum, array[randNum]);

	free(array);
	return 0;
}
