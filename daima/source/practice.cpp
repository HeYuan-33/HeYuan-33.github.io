#include<stdio.h>
#include<stdlib.h>

typedef struct Binode{
    int data;
    struct Binode *lchlid;
    struct Binode *rchild;
}Binode,*Bitree;

void creatbitree(Bitree *l)
{
    int t;
    (*l)=(Binode*)malloc(sizeof(Binode));
    scanf("%d",&t);
    if(t!=0)
    {
        (*l)->data=t;
        creatbitree(&(*l)->lchlid);
        creatbitree(&(*l)->rchild);
    }
    else
    (*l)=NULL;
}
void prebitree(Bitree l)
{
    if(l==NULL)
    return ;
        printf("%d",l->data);
        prebitree(l->lchlid);
        prebitree(l->rchild);
 }


int main()
{
    Bitree l;
    creatbitree(&l);
    prebitree(l);
    return 0;
}
