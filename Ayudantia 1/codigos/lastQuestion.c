#include <stdio.h>

void show_bits(unsigned int n)
{
	unsigned int mask = 1;
	int bit_size = 8;

	for(int i = bit_size;i >= 0;i--)
	{
	
		unsigned int bit = (n >> i) & mask;
		if(bit)
			putchar('1');
		else
			putchar('0');
	
	}
	putchar('\n');
}


int main()
{
	show_bits(5);
	return 0;

}
