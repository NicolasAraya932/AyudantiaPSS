#include<stdio.h>
#include<stdlib.h>

int existe_caracter(char *x, char *y){
    //primero obtenemos el largo del string X
    int len=0;
    //para que no pierda sus datos creamos un aux
    while(*x){
	if(*x == *y) { return 1; }
        x++;
    }
    return 0;
}

int existe_caracter2(char *x, char *y){
	    //primero obtenemos el largo del string X
    int len=0;
    //para que no pierda sus datos creamos un aux
    char* aux = x;
    while(*aux){
        len++;
        aux++;
    }
    for(;len >= 0;len--) { //según el largo recorremos los caracteres del string y buscamos
        if (x[len] == *y) { return 1; }
    }
    return 0;
}

void chequear_caracter(char *x, char *y, int ans) {
    if (existe_caracter(x, y) != ans) {
        printf("Error: existe_caracter(%s,%s) debe retornar %d.\n", x, y, ans);
        exit(1);
    } 
}

int main(){
    chequear_caracter("abcdef","a",1);
    chequear_caracter("abcdef","g",0);
    chequear_caracter("aaaaaa","b",0);
    chequear_caracter("abcdefg","g",1);
    chequear_caracter("abcdef","0",0);
    chequear_caracter("1230456","0",1);
		printf("DONE");
}
