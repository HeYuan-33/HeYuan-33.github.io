#include <stdio.h>
#include <stdlib.h>

// the structure of binary trees
typedef char DataType;
typedef struct BiTNode
{
    DataType data;
    struct BiTNode *lchild, *rchild;
}LinkBiTree;

// Likned list structure
typedef struct LNode
{
	LinkBiTree *tree;
	struct LNode *next;
}LinkNode;

typedef struct QNode
{
    LinkNode *head;
    LinkNode *tail;
}LinkList;

void HeadInsert(LinkList *L, LinkBiTree *TNode)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->tree = TNode;
    s->next = L->head;
    L->head = s;  
}

LinkBiTree* HeadDelete(LinkList *L)
{
    LinkBiTree *p = NULL;
    if (L->head)
    {
        p = L->head->tree;
        L->head = L->head->next;
    }
    return p;
}

void CreateBiTree(LinkBiTree **T)
{
	char ch;
	scanf("%c", &ch);
	if(ch == '#')
    {
		(*T) = NULL;
    }
	else
	{
		(*T) = (LinkBiTree *)malloc(sizeof(LinkBiTree));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

// preorder traversal
void PreOrderTraverse(LinkBiTree *T)
{
    LinkList *S;
    S->head = S->tail = NULL;
    LinkBiTree *p = T, *q;
    while (p || S->head)
    {
        if (p)
        {
            printf("%c ", p->data);		
            HeadInsert(S, p);			
            p = p->lchild;	
        }			
        else
        {
            q = HeadDelete(S);			
            p = q->rchild;				
        }   
    }
}

// inorder traverse
void InOrderTraverse(LinkBiTree *T)
{
    LinkList *S;
    S->head = S->tail = NULL;

    LinkBiTree *p = T, *q;
    while (p || S->head)
    {
        if (p)
        {
            HeadInsert(S, p);		
            p = p->lchild;			
        }
        else
        {
            q = HeadDelete(S);		
            printf("%c ", q->data);
            p = q->rchild;			
        }
    }
}

// postordertraver
void PostOrderTraverse(LinkBiTree *T)
{

    LinkList *S;
    S->head = S->tail = NULL;

    LinkBiTree *p = T, *parent;
    while (p || S->head)
    {
        while (p)
        {
            HeadInsert(S, p);	
            p = p->lchild;		
        }
        if (S->head)
        {
            parent = S->head->tree;		// get parent
            if (parent->rchild && parent->rchild != T)
            {
                p = parent->rchild;	// go throudh the right chijd
            }
            else
            {
                printf("%c ", parent->data);	// output root node
                T = parent;		// 设置新的根节点，用于表示该parent父结点已被访问（回溯）			
                HeadDelete(S);	
            }
        }
    }
}

int main()
{
    LinkBiTree *T;
	printf("请输入构建序列('#'为空):");
	CreateBiTree(&T);
	printf("\n");

    printf("非递归前序遍历:");
	PreOrderTraverse(T);
	printf("\n\n");

	printf("非递归中序遍历:");
	InOrderTraverse(T);
	printf("\n\n");
	
	printf("非递归后序遍历:");
	PostOrderTraverse(T);
	printf("\n\n");


    return 0;
}
