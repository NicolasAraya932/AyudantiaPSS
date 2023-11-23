#include <unistd.h>


void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int main(){

	_putchar(97);
	_putchar('\n');

	return 0;
}
