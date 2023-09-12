#include <stdio.h>


int XOR(int n, int m)
{
	return (~n & m) | (n & ~m);
}


int main()
{
	int m =5;
	int n = 2;

	int r = XOR(n ,m);

	printf("%d", r);
	return 0;
}
