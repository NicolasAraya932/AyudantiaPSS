#include <stdio.h>
#include <stdlib.h>

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

void reverse_string(char *str)
{
	char *i = str;
	char *j = str + string_len(str);
	char temp;
	
	while ( *str != '\0' )
	{

		if (*i != *j)
		{
			break;
		}
	}

}

void reverse_string_2(char *str)
{
	int j = string_len(str);
	char temp;

	for ( int i = 0; i < string_len(str) / 2 ; i++)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
	}
}


char *reverse_string_3(char *str)
{
	int len = string_len(str);
	int j = len - 1;

	char *resultado = malloc(sizeof(char)*len);
	
	for ( int i = 0; i < len ; i++)
	{
		resultado[i] = str[j];
		j--;	
	}
	return resultado;
}

int main()
{
	char *str = "hola";
	char *resultado = reverse_string_3(str);

	printf("%s", resultado);
	return 0;
}
