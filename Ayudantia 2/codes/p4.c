#include <stdio.h>

void swp_int(int *a, int *b)
{
	/* No cambia la direccion de la variable
	 * solo el valor asignado a esta
	 * "Puntero de Desreferencia"
	 */
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
	int a = 3;
	int b = 5;

	// Punteros de referencia
	swp_int(&a, &b);

	return 0;
}

