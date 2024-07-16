#include<stdio.h>
#include<stdlib.h>

struct List{
    int data;
    struct List *next;
};
struct List* creatList()
{
    struct List *head,*end,*p;
    int n;
    head=(struct List*)malloc(sizeof(struct List));
    end=head;
    scanf("%d",&n);
    while(n!=-1)
    {
        p=(struct List*)malloc(sizeof(struct List));
        p->data=n;
        end->next=p;
        p->next=NULL;
        end=p;
        scanf("%d",&n);
    }
    return head;
}
int main()
{
    struct List *la,*lb,*p,*q1,*q2;
    la=creatList();
    lb=creatList();
    q1=la->next;
    q2=lb->next;

    while(q2!=NULL)
    {
        q1=la->next;
        
        while(q1!=NULL && q1->data!=q2->data)
        {
            q1=q1->next;
        }
        
        if(q1==NULL)
        {
            p=q2;
            q2=q2->next;
            p->next=la->next;
            la->next=p;
        }
        else
        {
            q2=q2->next;
        }
    }
    
    q1=la->next;
    while(q1!=NULL)
    {
        printf("%d ",q1->data);
        q1=q1->next;
    }
    
    return 0;
}