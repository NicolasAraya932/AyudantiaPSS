#include <stdio.h>


int main()
{
	int c;
	printf("Estimado usiario, deme una palabra");
	while((c=getchar()) != '\n')
	{
		printf("%d,", c);	
	}
	printf("Gracias Usuario");

	return 0;

}
