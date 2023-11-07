#include <stdio.h>


typedef struct nodo {
    int x;
    struct nodo *izq, *der;
} NodoABB;


// Ejemplo búsqueda en ABB
int buscar(NodoABB *pa, int y){ 
    if(pa==NULL)
        return 0;

    if( pa->x == y )
        return 1;
    
    else if( pa->x < y)
        return buscar(pa->izq,  y );

    else
        return buscar(pa->der, y);
}

// podar
// Elimina los nodos con valores mayores a y
void podar( NodoABB **pa , int y) {
    NodoABB *a = *pa;
    if( a == NULL) {
        return;
    }
    if( a->x <= y ) {
        podar(&a->der, y) ;
    } 
    else {
        podar(&a->izq, y) ;
        *pa = a->izq; // de esta manera los cambios se reflejan en pa
    }
 }

void printarbol(NodoABB* pa){
    printf("( %d ", pa->x);    
    if(pa->izq == NULL)
        printf(". ");
    else
        printarbol(pa->izq);
    if(pa->der == NULL)
        printf(".");
    else
        printarbol(pa->der);
    printf(")");
}


int main()
{
    NodoABB *raiz;
    NodoABB v, s, u, x, w;
    
    v.x = 10;
    s.x = 5;
    u.x = 8;
    x.x = 15;
    w.x = 12;
    
    v.izq = &s; 
    v.der = &x;
    s.der = &u;
    s.izq = NULL;
    x.izq = &w;
    x.der = NULL;
    w.izq = NULL;
    w.der = NULL;
    u.izq = NULL;
    u.der = NULL;
    raiz = &v;
    
    printarbol(raiz);
    podar(&raiz, 11);
    printf("\n");
    printarbol(raiz);
    printf("\n");
    
    return 0;
    
}
