#include <stdio.h>

int string_len(char *str)
{
	// *str corresponde a una cadena de varios char
	int len = 0;
	while ( *str != '\0'){
		len++;
		// Se recorre la cadena de char
		str++;
	}
	return len;
}

int main()
{
	char *str = "Hello World";
	printf("String len of %s is %d\n", str, string_len(str));

	return 0;
}
