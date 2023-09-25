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

char *reverse_string(char *str)
{
	// Conocer la importancia de las variables locales
	int len = string_len(str);
	/* ans es una variable local de reverse_string y
	 * cuando termine de ejecutarse la funcion ans
	 * desaparecera y no podra ser utilizada,
	 */
	char ans[sizeof(char)*len];
	
	int j = len - 1;

	while ( *str != '\0')
	{
		ans[j] = *str++;
		j--;
	}
	printf("%s", ans);

	return ans;	
}


int main()
{
	char *str = "hola";

	char *rts = reverse_string(str);

	printf("\n%s", rts);
	return 0;
}
