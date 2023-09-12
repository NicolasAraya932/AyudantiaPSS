#include <stdio.h>

int int_size(int n)
{
	int contador = 0;
 	while(n)
	{
		n = n >> 1;
		contador++;
	}
	return contador;
}

int main()
{
	int n = 5;
	int r = int_size(n);
	printf("%d", r);

	return 0;


}
