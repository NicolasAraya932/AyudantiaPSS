#include <stdio.h>
#include <stdlib.h>

char *ptr = NULL;

int main()
{
	for(int i = 1;i <= 101; i++)
	{
		ptr = malloc(i);
	}

	return 0;
}
