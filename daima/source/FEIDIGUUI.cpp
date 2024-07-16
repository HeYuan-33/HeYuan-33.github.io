#include<stdio.h>
#include<stdlib.h>

typedef struct Bitree{
    char data;
    struct Bitree *lchild;
    struct Bitree *rchild;
}LinkBiTree;

typedef struct LNode{
    LinkBiTree *tree;
    struct LNode *next;
}LinkNode;

typedef struct QNode{
    LinkNode *head;
    LinkNode *end;
}LinkList;

void CreateBiTree(LinkBiTree **t)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        *(t)=NULL;
    }
    else
    {
       (*t)=(LinkBiTree*)malloc(sizeof(LinkBiTree));
       (*t)->data=ch;
       CreateBiTree(&(*t)->lchild);
       CreateBiTree(&(*t)->rchild);
    }
}

void PreOrderTraverse(LinkBiTree *t)
{
    if(t)
    {
     printf("%c",t->data);
     PreOrderTraverse(t->lchild);
      PreOrderTraverse(t->rchild);
    }
}

void InOrderTraverse(LinkBiTree*t)
{
    if(t)
    {
        InOrderTraverse(t->lchild);
        printf("%c",t->data);
        InOrderTraverse(t->rchild);
    }
}

void PostOrderTraverse(LinkBiTree *t)
{
    if(t)
    {
        PostOrderTraverse(t->lchild);
        PostOrderTraverse(t->rchild);
        printf("%c",t->data);
    }
}

int main()
{
    LinkBiTree *t;
    CreateBiTree(&t);
    PreOrderTraverse(t);
    InOrderTraverse(t);
    PostOrderTraverse(t);
}

