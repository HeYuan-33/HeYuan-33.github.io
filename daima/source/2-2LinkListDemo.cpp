#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 struct List
{
    int data;
    struct List *next;
};
struct List* Creat()
{
    struct List *head,*p,*end;
    head=(struct List*)malloc(sizeof(struct List));
    end=head;
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        p=(struct List*)malloc(sizeof(struct List));
        p->data=n;
        end->next=p;
        p=end;
        scanf("%d",&n);
    }
    return head;
}
struct List* MergeList_l(struct List *la,struct List *lb,struct List *lc)
{

    struct List *pa,*pb,*pc;
    pa=la->next;
    pb=lb->next;
    pc=lc;
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;

}
int main()
{
    struct List *la,*lc,*lb;
    lc==(struct List*)malloc(sizeof(struct List));
    la=Creat();
    lb=Creat();
    MergeList_l(la,lb,lc);
    while(lc->next!=NULL)
    {
        printf("%d ",lc->data);
        lc=lc->next;
    }
    return 0;
}
