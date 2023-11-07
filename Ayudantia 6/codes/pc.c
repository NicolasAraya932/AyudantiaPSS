#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMTHREAD 3


typedef struct {
	int id;
	int price;
	char *name;
} Product;

typedef struct {
	int in, out, size, cnt, end;
	Product **array;

} Buffer;

Buffer *create_buffer(int size)
{
	Buffer *buf = (Buffer *) malloc(sizeof(Buffer));
	buf->array = (Product **) malloc(sizeof(Product *) * size); 
	buf->size = size;
	buf->in = 0;
	buf->out = 0;
	buf->cnt = 0;
	buf->end = 0;

	return buf;
}

Product *create_product(int id)
{
	Product *product = (Product *) malloc(sizeof(Product));
	id = id % 4;
	product->id = id;
	product->price = 3000 * id;
	if(id == 0) product->name = "zanahoria";
	if(id == 1) product->name ="zapallo";
	if(id == 2) product->name = "platano";
	if(id == 3) product->name  = "papa";

	return product;
}


void put(Buffer *buf, Product *product)
{
	buf->array[buf->in] = product;
	buf->in = (buf->in + 1) % (buf->size);
	buf->cnt++;
}

void factory_function(void *arg)
{	
	Buffer *buf = (Buffer *) arg;
	for(int i = 0; i < 100;i++)
	{
		Product *product = create_product(i);
		put(buf, product);
	}
	buf->end = 1;
}

Product *get(Buffer *buf)
{
	Product *product;
	while(buf->cnt == 0)
		{
			while(buf->end == 1)
			{
				return NULL;
			}
		}
		product = buf->array[buf->out];
		buf->out = (buf->out + 1) % (buf->size);
		buf->cnt--;
		return product;
}

void cliente_funcion(void *arg)
{
	Buffer *buf = (Buffer *) arg;
	for(;;)
	{
		Product *product = get(buf);
		if(product == NULL)
		{
			break;
		}
	}
}

int main()
{
	pthread_t t_factory, t_cliente1, t_cliente2;
	Buffer *buf = create_buffer(10);

	pthread_create(&t_factory, NULL,(void *) factory_function, (void *) buf);
	pthread_create(&t_cliente1, NULL,(void *) cliente_funcion, (void *) buf);
	pthread_create(&t_cliente2, NULL,(void *)  cliente_funcion, (void *) buf);

	pthread_join(t_factory, NULL);
	pthread_join(t_cliente1, NULL);
	pthread_join(t_cliente2, NULL);
}
