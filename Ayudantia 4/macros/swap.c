#include <stdio.h>

#define SWAP(x, y, T) \
			do { \
				T temp = x; \
				x = y; \
				y = temp; \
			} while(0)


int main()
{
	int x = 2;
	int y = 3;

	SWAP(x, y, int);
   
	printf("x = %d\t y = %d\nLASTSTATE x = %d, y = %d\n", x, y, y, x);
	
	return 0;
}
