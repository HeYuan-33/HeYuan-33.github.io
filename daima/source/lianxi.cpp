#include<stdio.h>
#include<stdlib.h>

typedef struct Binode {
    int data;
    struct Binode* rchild;
    struct Binode* lchild;
} Binode, *Bitree;

void creatBitree(Bitree* bt) {
    int t;
    scanf("%d", &t);
    if (t != 0) {
        (*bt) = (Binode*)malloc(sizeof(Binode));
        (*bt)->data = t;
        creatBitree(&(*bt)->lchild);
        creatBitree(&(*bt)->rchild);
    }
    else
        (*bt) = NULL;
}

void preBitree(Bitree l) {
    if (l == NULL)
        return;
    printf("%d ", l->data);
    preBitree(l->lchild);
    preBitree(l->rchild);
}

int main() {
    Bitree l = NULL;

    printf("请输入二叉树：");
    creatBitree(&l);
    printf("前序历遍：");
    preBitree(l);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// 二叉树结点结构
typedef char DataType;
typedef struct BiTNode
{
    DataType data;
    struct BiTNode *lchild, *rchild;
}LinkBiTree;

// 链表结点结构
typedef struct LNode
{
	LinkBiTree *tree;
	struct LNode *next;
}LinkNode;

// 用于同时表示栈和队列
typedef struct QNode
{
    LinkNode *head;
    LinkNode *tail;
}LinkList;

// 头插：对应入栈操作
void HeadInsert(LinkList *L, LinkBiTree *TNode)
{
    // 创建新结点
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->tree = TNode;
    // 插入结点
    s->next = L->head;
    L->head = s;  
}

// 尾插：对应入队操作
void TailInsert(LinkList *L, LinkBiTree *TNode)
{
    // 创建新结点
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->tree = TNode;
    // 插入结点
    if (L->tail)
    {
        L->tail->next = s;
    }
    else
    {
        L->head = s;
    }
    L->tail = s;
}

// 头删：同时对应<出栈>和<出队>操作
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

//创建二叉树
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

// 非递归先序遍历
void PreOrderTraverse(LinkBiTree *T)
{
    // 初始化栈
    LinkList *S;
    S->head = S->tail = NULL;

    LinkBiTree *p = T, *q;
    while (p || S->head)
    {
        if (p)
        {
            printf("%c ", p->data);		// 先输出根结点（根）
            HeadInsert(S, p);			// 入栈根结点
            p = p->lchild;				// 向左孩子遍历（左）
        }
        else
        {
            q = HeadDelete(S);			// 出栈栈顶元素
            p = q->rchild;				// 获取右孩子结点（右）
        }   
    }
}

// 中序遍历
void InOrderTraverse(LinkBiTree *T)
{
    // 初始化栈
    LinkList *S;
    S->head = S->tail = NULL;

    LinkBiTree *p = T, *q;
    while (p || S->head)
    {
        if (p)
        {
            HeadInsert(S, p);		// 先入栈根结点
            p = p->lchild;			// 向左孩子遍历（左）
        }
        else
        {
            q = HeadDelete(S);		// 出栈栈顶元素
            printf("%c ", q->data);	// 输出根结点（根）
            p = q->rchild;			// 向右孩子遍历（右）
        }
    }
}

// 后序遍历
void PostOrderTraverse(LinkBiTree *T)
{
     // 初始化栈
    LinkList *S;
    S->head = S->tail = NULL;

    LinkBiTree *p = T, *parent;
    while (p || S->head)
    {
        while (p)
        {
            HeadInsert(S, p);	// 入栈根结点
            p = p->lchild;		// 向左孩子遍历（左）
        }
        if (S->head)
        {
            parent = S->head->tree;		// 获取父结点
            if (parent->rchild && parent->rchild != T)
            {
                p = parent->rchild;	// 向右孩子遍历（右）
            }
            else
            {
                printf("%c ", parent->data);	// 输出根结点 （根）
                T = parent;		// 设置新的根节点，用于表示该parent父结点已被访问（回溯）			
                HeadDelete(S);	// 出栈
            }
        }
    }
}

// 层序遍历
void LevelOrderTraverse(LinkBiTree *T)
{
    // 初始化队列
    LinkList *Q;
    Q->head = Q->tail = NULL;

    LinkBiTree *p = T, *q;
    // 首先输出根结点，并入队根节点的左右孩子结点
    printf("%c ", p->data);
    if (p->lchild)
    {
        TailInsert(Q, p->lchild);
    }
    if (p->rchild)
    {
        TailInsert(Q, p->rchild);
    }
    // 出队
    q = HeadDelete(Q);
    while (q)
    {
        printf("%c ", q->data);
        if (q->lchild)
        {
            TailInsert(Q, q->lchild);
        }
        if (q->rchild)
        {
            TailInsert(Q, q->rchild);
        }
        q = HeadDelete(Q);
    }
}


int main()
{
    LinkBiTree *T;
	printf("请输入构建序列('#'为空):");
	//测试用例:ABC#D###E#FG###
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

	printf("层序遍历:");
	LevelOrderTraverse(T);
	printf("\n\n");

    return 0;
}
