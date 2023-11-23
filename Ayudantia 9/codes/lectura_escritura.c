#include <stdio.h>
#include <unistd.h>


void _putchar(char c){
	// 1 como salida estandar
	write(0, &c, 1);
}

int main()
{
	_putchar(97);
	printf("\n");

	return 0;
}
