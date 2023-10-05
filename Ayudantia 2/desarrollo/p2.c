#include <stdio.h>

int string_len(char *str)
{
	int len = 0;

	while ( *str != '\0')
	{
		str++;
		len++;
	}
	return len;
}

void copy_string(int x, int *y)
{
	x = *y;
}
int main()
{
	char *str = "hola mundo";
	char dest[sizeof(char)*string_len(str)];
	int x = 2;
	int y;
	
	copy_string(x, &y);

	printf("%d", y);

	return 0;
}

