#include <stdio.h>

int int_size(int n)
{
	int c = 0;
	while(n)
	{
		n = n >> 1;
		c++;
	}
	
	return c;
}

unsigned int bit_significativo(unsigned int n)
{
	int s = int_size((int)n);
	unsigned int m = n >> (s - 1);
	return m << (s - 1);
}

int XOR(int m, int n)
{
	return (~n & m) | (n & ~ m);
}

unsigned int unset1(unsigned int n)
{
	unsigned int mask = bit_significativo(n);

	return XOR(mask, n);
}

int main()
{
	unsigned int n = 5;

	unsigned int bit = bit_significativo(n);

	unsigned int unset = unset1(5);

	printf("%d\n unset1: %d", bit, unset);

	return 0;

}
