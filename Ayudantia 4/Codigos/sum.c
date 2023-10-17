#include <stdio.h>
#include <stdarg.h>

int sum(int numeros, ...)
{
	va_list ap;
	int i;
	int count = 0;

	va_start(ap, numeros);
	for(i = numeros; i != -1; i = va_arg(ap, int))
	{
		count += i;
	}
	va_end(ap);

	return count;
}

int main()
{
	int x = sum(4, 3, 6, 2);

	printf("%d\n", x);

	return 0;
}

