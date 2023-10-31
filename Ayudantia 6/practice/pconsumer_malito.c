#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int FRUIT[4];
int TOTAL;

typedef struct{
    int id;
    int price;
    char *name;
} Product;

typedef struct{
    int in, out, size, cnt, end;
    Product **array; 

} Buffer;


Buffer *create_buffer(int size){
    Buffer *buf = (Buffer*) malloc(sizeof(Buffer));
    buf->array = (Product**) malloc(size * sizeof(Product*));
    buf->size = size;
    buf->in = buf->out = buf->cnt = buf->end = 0;
    return buf;
}

Product *create_product(int id){
    Product *product = malloc(sizeof(Product));
    id = id%4;
    product->id = id;
    product->price = (id + 1)*3;
    if(id == 0) product->name = "Apple";
    else if (id == 1) product->name = "Pear";
    else if (id == 2) product->name = "Banana";
    else if (id == 3) product->name = "Kiwi";
    return product;
}

void put(Buffer *buf, Product *product){
    while(buf->size == buf->cnt);
    buf->array[buf->in] = product;
    buf->in = (buf->in+1)%(buf->size);
    buf->cnt++;
    
}

Product *get(Buffer *buf){
    Product *product;
    while(buf->cnt == 0){
        if (buf->end == 1){
            return NULL;
        }
    
    }
    product = buf->array[buf->out];
    buf->out = (buf->out+1)%(buf->size);
    buf->cnt--;

    return product;
}


void *producer(void* ptr){
    Buffer *buf = (Buffer*) ptr; 
    for(int i = 0 ; i < 100000; i++){
        Product *product = create_product(i);
        put(buf, product);
    }   
    buf->end = 1;
    return NULL;
}

void update_information(Product *product){
    FRUIT[product->id]++;
    TOTAL++;
    
}

void* consumer(void* ptr){
    Buffer *buf = (Buffer*) ptr;
    int total_price = 0;
    for(;;){
        Product *product = get(buf);
        if (product == NULL)
            break;
        update_information(product);
        total_price = total_price + (product->price / 2);
    }
    printf("total price: \t$%d\n", total_price);
    return NULL;
}

int main(){
    TOTAL = 0;
    for(int i = 0; i < 4; i++)
        FRUIT[i]=0;
    pthread_t t_factory, t_client1, t_client2;
    Buffer *buf = create_buffer(10);

    pthread_create(&t_factory, NULL, producer,(void *) buf);
    pthread_create(&t_client1, NULL, consumer,(void *) buf);
    //pthread_create(&t_client2, NULL, consumer,(void *) buf);

    pthread_join(t_factory, NULL);
    pthread_join(t_client1, NULL);
    //pthread_join(t_client2, NULL);
    printf("\n\n");
    for(int i = 0; i < 4; i++)
        printf("id: %d, totales:%d\n", i, FRUIT[i]);
    printf("TOTAL: \t %d\n",TOTAL);

    return 0;
}
