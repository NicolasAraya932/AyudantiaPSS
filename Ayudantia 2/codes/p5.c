#include <stdio.h>
#include <stdlib.h>

int string_len(char *str)
{
	int len = 0;
	while ( *str != '\0'){
		len++;
		str++;
	}
	return len;
}

char * reverse_string(char *str)
{
	int len = string_len(str);

	char *ans = malloc(sizeof(char)*len);

	int j = len - 1;

	while (*str != '\0')
	{
		ans[j] = *str++;
		j--;
	}

	return ans;
}
int main()
{
	char *str = "Earth is a great place to live";
	char *r = reverse_string(str);
	printf("REVERSED: %s\n", r);
	free(r);
	return 0;
}
