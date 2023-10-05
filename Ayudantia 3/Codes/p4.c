#include <stdio.h>

// Devuelve 1 si son iguales, 0 en caso contrario
int comparar_string(char *x, char *y){
	// Mientras x no sea nulo
	// y mientras lo que apunta x (char)
	// sea igual a lo que apunta y (char)
	// avanzamos el puntero x e y en 1.
    while(*x && *x==*y){
        x++;y++;
    }
	// Si al salir del while, ambos strings terminaron
	// entonces son iguales (retornamos 1)
    if (*x=='\0' && *y=='\0') return 1;
    return 0;
}

int same_len(char *x, char *y)
{
	int len_x = 0;
	int len_y = 0;
	while(*x != '\0')
	{ x++; len_x++; }
	while(*y != '\0')
	{ y++; len_y++; }

	if(len_x != len_y)
		return 0;

	return 1;
}

int comparar_string2(char *x, char *y)
{
	int i = 0;

	if(!same_len(x, y))
		return 0;

	while(*x != '\0')
	{
		if(*x != *(y+i))
		{
			return 0;
		}
		x++;
		i++;
	}
	return 1;
}


int main()
{
	char *hola = "Hola";
	char *x = "Hola";

	if(comparar_string(hola, x))
	{
		printf("Son Iguales\n");
	}

	return 0;
}
