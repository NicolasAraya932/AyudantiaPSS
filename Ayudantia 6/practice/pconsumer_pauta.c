#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int FRUIT[4];
int TOTAL;
pthread_mutex_t mtx_cnt; 


typedef struct{
    int id;
    int price;
    char *name;
} Product;

typedef struct{
    int in, out, size, cnt, end;
    Product **array; 
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} Buffer;

Buffer *create_buffer(int size){
    Buffer *buf = (Buffer*) malloc(sizeof(Buffer));
    buf->array = (Product**) malloc(size * sizeof(Product*));
    buf->size = size;
    buf->in = buf->out = buf->cnt = buf->end = 0;
    pthread_mutex_init(&buf->mtx, NULL);
    pthread_cond_init(&buf->cond, NULL);
    return buf;
}

Product *create_product(int id){
    Product *product = malloc(sizeof(Product));
    id = id%4;
    product->id = id;
    product->price = rand()%10 + id;
    if(id == 0){
        product->name = "Manzana";
    }
    else if (id == 1)
    {
        product->name = "Pera";
    }
    else if (id == 2)
    {
        product->name = "Platano";
    }
    else if (id == 3)
    {
        product->name = "Kiwi";
    }
    return product;
}

void put(Buffer *buf, Product *product){
    pthread_mutex_lock(&buf->mtx);
    while(buf->size == buf->cnt)
        pthread_cond_wait(&buf->cond, &buf->mtx);
    buf->array[buf->in] = product;
    buf->in = (buf->in+1)%(buf->size);
    buf->cnt++;
    pthread_cond_broadcast(&buf->cond);
    pthread_mutex_unlock(&buf->mtx);
}

Product *get(Buffer *buf){
    Product *product;
    pthread_mutex_lock(&buf->mtx);
    while(buf->cnt == 0){
        if (buf->end == 1){
            pthread_cond_broadcast(&buf->cond);
            pthread_mutex_unlock(&buf->mtx);        
            return NULL;
        }
        pthread_cond_wait(&buf->cond, &buf->mtx);
    }
    product = buf->array[buf->out];
    buf->out = (buf->out+1)%(buf->size);
    buf->cnt--;

    pthread_cond_broadcast(&buf->cond);
    pthread_mutex_unlock(&buf->mtx);
    return product;
}


void *producer(void* ptr){
    Buffer *buf = (Buffer*) ptr; 
    for(int i = 0 ; i < 100000; i++){
        Product *product = create_product(i);
        put(buf, product);
    }
    pthread_mutex_lock(&buf->mtx);
    buf->end = 1;
    pthread_cond_broadcast(&buf->cond);
    pthread_mutex_unlock(&buf->mtx);
    return NULL;
}

void update_information(Product *product, int* fruit){
//void update_information(Product *product){
    fruit[product->id]++ ;
    pthread_mutex_lock(&mtx_cnt);
    FRUIT[product->id]++;
    TOTAL ++;
    pthread_mutex_unlock(&mtx_cnt);
}

void* consumer(void* ptr){
    Buffer *buf = (Buffer*) ptr;
    int fruit[] = {0,0,0,0};
    int total_price = 0;
    for(;;){
        Product *product = get(buf);
        if (product == NULL)
            break;
        update_information(product, fruit);
        total_price = total_price + product->price;
    }
    printf("total price: \t$%d\n", total_price);
    return NULL;

}

int main(){
    TOTAL = 0;
    for(int i = 0; i < 4; i++)
        FRUIT[i]=0;
    pthread_t t_factory, t_client1, t_client2;
    int BUFF_SIZE = 10;
    Buffer *buf = create_buffer(BUFF_SIZE);

    pthread_mutex_init(&mtx_cnt, NULL);

    pthread_create(&t_factory, NULL, producer,(void *) buf);
    pthread_create(&t_client1, NULL, consumer,(void *) buf);
    pthread_create(&t_client2, NULL, consumer,(void *) buf);


    pthread_join(t_factory, NULL);
    pthread_join(t_client1, NULL);
    pthread_join(t_client2, NULL);
    printf("\n\n");
    for(int i = 0; i < 4; i++)
        printf("id: %d, totales:%d\n", i, FRUIT[i]);
    printf("TOTAL: \t %d\n",TOTAL);

    pthread_mutex_destroy(&mtx_cnt);

    return 0;
}
