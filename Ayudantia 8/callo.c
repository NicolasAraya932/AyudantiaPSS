#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nitems, size_t size)
{
	void *ptr = malloc(nitems*size);
	if(ptr == NULL)
	{
		return NULL;
	}
	for(size_t i = 0; i < nitems ;i++)
	{
		*((char *)ptr + i * size) = 0;
	}

	return ptr;
}

void *calloc2(size_t nitems, size_t size)
{
	void *ptr = malloc(nitems*size);
	if(ptr == NULL)
	{
		return NULL;
	}

	memset(ptr, 0, nitems * size);

	return ptr;
}

