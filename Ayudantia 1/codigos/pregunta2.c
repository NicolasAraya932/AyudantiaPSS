#include <stdio.h>


int main()
{

	int c;
	int a = 0;
	while((c=getchar()) != EOF)
	{	
		if(c == 'a')
		{
			a++;
		}
	}
	
	printf("\n%d\n", a);

	return 0;
}
