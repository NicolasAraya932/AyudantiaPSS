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

int main()
{
	char *str = "hola mundo";
	printf("El largo es %d", string_len(str));

	return 0;

}
