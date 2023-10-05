#include <stdio.h>

int str_len(char *str)
{
	int len = 0;
	while( *str != '\0' )
	{
		len++;
		str++;
	
	}
	return len;
}

int palindromo(char *str)
{
	char *i = str;
	char *j = str + str_len(str) - 1;
	while ( i < j )
	{
		if(*i != *j) 
			return 0;
		i++;
		j--;
	}
	return 1;
}

int palindromo_2(char *str)
{
	int j = str_len(str) - 1;

	for ( int i = 0 ; i < str_len(str) ; i++ )
	{
		if ( str[i] != str[j] )
		{
			return 0;
		}
		j--;
	}
	return 1;

}


int main()
{
	char *str = "reconocer";

	if (palindromo_2(str))
	{
		printf("es palindromo");
	}
	
	return 0;
}
