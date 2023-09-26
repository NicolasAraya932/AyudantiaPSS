#include <stdio.h>

int string_len(char *str)
{
	int len = 0;
	while ( *str != '\0'){
		len++;
		str++;
	}
	return len;
}

void reverse_string(char *str)
{
	// Version correcta utiliza la misma direccion de memoria de str
	char aux;

	int len = string_len(str);
	
	int j = len - 1;

	for( int i = 0 ; i < len / 2 ; i++ )
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		j--;
	}
}


int main()
{
	char str[] = "hola";

	reverse_string(str);

	printf("REVERSED: %s\n", str);
	return 0;
}
