#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REMAINDER 13
#define SIZE 50 

typedef struct element
{
	int key;			
}Element;

typedef struct table
{
	Element **elm;	
	int count;		
	int size;	
}Table;

int hash(int key)
{
	return key%REMAINDER;	
}

Table * init_Table()
{
	Table *t = (Table*)malloc(sizeof(Table));
	t->size = SIZE;
	t->count = 0;
	t->elm = (Element **)malloc(SIZE*sizeof(Element*));
	int i;
	for(i=0 ; i<t->size ; i++)
	{
		t->elm[i] = NULL;	
	}	
	return t;
}

void Insert(Table *t,Element * k)		
{
	int i=0,s;
	int position;
	position = hash(k->key);
	
	for(i=1 ; t->elm[position]!=NULL && i<t->size ;i++ )
	{

		position = hash(k->key);
        s=pow(i,2);
		position=(hash(position)+s)%t->size;
	}
	t->elm[position] = k;	
	t->count += 1;
	return ;
}

void Print_Table(Table *t)		
{
	int i;
	for(i=0 ; i<13 ; i++)
	{
		if(t->elm[i])
		printf("%d  ",t->elm[i]->key);
		else printf("NULL ");
	}	
	printf("\n");
}

int main()
{
	Table *t = init_Table();
	
	Element a[]={12,13,26,14,15,10,27};
	int length = sizeof(a)/sizeof(Element);
	
	int i;
	for(i=0 ; i<length ; i++)
	{
		Insert(t,&a[i]);
	}
    
	Print_Table(t);
	return 0;
	
}


