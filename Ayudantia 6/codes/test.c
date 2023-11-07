#include <stdio.h>


int main()
{
	int counter = 0;
	for(int i = 0; i < 40;i++)
	{
		counter = (counter + i) % 5;
		printf("%d\n", counter);
	}

	return 0;
}
