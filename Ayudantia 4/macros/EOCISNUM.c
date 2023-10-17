#include <stdio.h>
#include <stdlib.h>

#define EOC(x) (((x) != '\0') ? 1 : 0)
#define ISNUM(c) (((c) >= '0' && (c) <= '9') ? \
												 (c) - '0' : 999)

/* Tamanno del string */
int getSize(char *exp)
{
	int size = 0;
	while(EOC(*exp))
	{
		if(ISNUM(*exp) != 999)
			size++;
		exp++;
	}
	return size;
}
/* Obtencion de los numeros del string  */
int *getNumbers(char *exp)
{
	int size = getSize(exp);

	int *num = (int*)malloc(size);
	if(num == NULL)
	{
		return 0;
	}

	int i = 0;
	while(EOC(*exp))
	{
		if(ISNUM(*exp) != 999)
		{
			*(num + i) = *exp - '0';
			i++;
		}
		exp++;
	}

	return num;
}


int main()
{
	char *str = "3 + 5 * 8";

	int *nums = getNumbers(str);

	return 0;
}
