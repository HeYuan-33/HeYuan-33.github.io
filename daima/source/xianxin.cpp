#include<stdio.h>
#include<stdlib.h>

#define REMAINDER 11	

typedef struct element
{
	int key;
	int value;
	int hash;
}Element;

typedef struct Pnode
{
	Element *data;
	struct Pnode *next;
}Node;

typedef struct hash_table
{
	int size;
	int length;
	struct Pnode *head;
}Hash_table;


int hash(int value)
{
	return value%REMAINDER;
}

Hash_table* Creat_Table(int table_size)
{
	Hash_table *h = (Hash_table *)malloc(sizeof(Hash_table));
	h->size = REMAINDER;
	h->head = (Node *)malloc((h->size)*sizeof(Node));
	h->length = 0;
	int i = 0;
	for(i=0 ; i<h->size ; i++)
	{
		h->head[i].next = NULL;
	}
	return h;
}

Node *lookup(Hash_table *h , int key)
{
	int i;
	i = hash(key);
	Node * p = h->head[i].next;
	while(p && key != p->data->key)
	{
		p = p->next;
	}

	return p;
}

void Insert(Hash_table *h , Element k)
{
	Node * p = lookup(h,k.key);
	if(!p)
	{
		Node *q = (Node *)malloc(sizeof(Node));
		q->data = (Element *)malloc(sizeof(Element));
		(q->data)->key = k.key;
		(q->data)->value = k.value;
		int position;
		position = (q->data)->hash  = hash(k.key);
		q->next = h->head[position].next;
		h->head[position].next = q;
		
		h->length += 1; 
		return ;
	}
	
}

void print_Table(Hash_table *h)
{
	int i = 0; 
	for (i = 0; i < h->size ; i++)
    {
        Node * p = h->head[i].next;
        while (p)
        {
            printf("%d ",p->data->key);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main()
{
	Element a[]={{12},{13},{26},{14},{15},{10}};
	
	int n = sizeof(a)/sizeof(Element);
	Hash_table *h = Creat_Table(n);
	int i = 0;
	for(i = 0 ; i<n ; i++)
	{
		Insert(h,a[i]);
	}
	print_Table(h);		
	return 0;
}
