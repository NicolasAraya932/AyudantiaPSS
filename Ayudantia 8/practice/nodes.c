#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}typedef node;


node *merge(node *listA, node *listB)
{
	node *r = (node *)malloc(sizeof(node));
	node *ptr = r;

	while(listA != NULL && listB != NULL)
	{
		if(listA->data > listB->data)
		{
			r = listA;
			listA = listA->next;
		}
		else{
			r = listB;
			listB = listB->next;
		}

		r = r->next;
	}

	return ptr;
}


void freeList(node *head)
{
	if(head == NULL)
		return;

	while(head != NULL)
	{
		node *aux = head;
		head = head->next;
		free(aux);
	}
}
