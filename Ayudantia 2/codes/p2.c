#include <stdio.h>

void copy_string(char *str, char *dest)
{
	while(*str != '\0')
	{
		*dest++ = *str++;
	}
	*dest = '\0';
}

int main()
{
	char *str = "My name is Joseph";
	char dest[sizeof(char)*5];

	copy_string(str, dest);

	printf("%s", dest);
	return 0;
}
