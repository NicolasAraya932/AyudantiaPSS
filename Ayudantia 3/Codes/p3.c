#include <stdio.h>
#include <stdlib.h>

// Devuelve la representacion binaria de x
char* convertir_a_string(unsigned int x){
	// Pedimos la memoria suficiente para almacenar el string (32 bits + 0)
    char* binary_string = (char*) malloc(32+1);
	// Creamos variables
    unsigned int aux;
    int bit;
    int i=0;
    while(i < 32){
		// Rescatamos el bit i-esimo
        aux = (x>>(31-i)) & 1;
		// en bit recuperamos el bit i-esimo (0 o 1)
        if(aux) bit = 1;
        else bit = 0;
		// si es 1, el puntero binary_string+i apuntara a '1'
		// en caso contrario lo hara con el '0'
        *(binary_string+i) = bit + '0';
        i++;
    }
	// Finalizamos el string
    *(binary_string+i) = '\0';
    return binary_string;
}

char* convertir_a_string2(unsigned int x){

    char *resultado = malloc(32*sizeof(char));

    unsigned int aux = x;

    for(int i=0;i<=31;i++){
	    aux = x<<i;
	    aux = aux>>31;
	    aux = aux<<31;
	    if(aux!=0){
	    	resultado[i]=*"1";
	    }else{resultado[i]=*"0";}
    }

    return resultado;
}

int main(){
    unsigned int k = 7;

    printf("%s", convertir_a_string(k));

    return 0;
}
