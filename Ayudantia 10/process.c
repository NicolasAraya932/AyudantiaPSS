#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("RUNNING PS\n");
	system("ps -ax &"); // ps -ax &
	printf("DONE\n");
	
	exit(0);
}
