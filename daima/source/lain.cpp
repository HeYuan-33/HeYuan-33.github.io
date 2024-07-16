#include<stdio.h>
#include<stdlib.h>

typedef struct qlink{
    int data;
     struct qlink *next;
}qlink;

qlink* creatlink()
{
    qlink *head,*q,*p;
    int a;
    head=(qlink*)malloc(sizeof(qlink));
    q=head;
    scanf("%d",&a);
    while(a!=-1)
    {
        p=(qlink*)malloc(sizeof(qlink));
        p->data=a;
        q->next=p;
        q=p;
        scanf("%d",&a);
    }
    return head;

}
qlink* comb(qlink *head1,qlink *head2)
{
    qlink *head,*p3,*p1,*p2;
    p1=head1->next;
    p2=head2->next;
    head=(qlink*)malloc(sizeof(qlink));
    p3=head;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p2->data<=p1->data)
        {
           p3->next=p2;
           p3=p2;
           p2=p2->next;
        }
        else
        {
            p3->next=p1;
            p3=p1;
            p1=p1->next;
        }
    }
    if(p1!=NULL)
    p3->next=p1;
    else if(p2!=NULL)
    p3->next=p2;
    return head;
}

int main()
{
   qlink *s1,*s2,*s3;
   s1=creatlink();
   s2=creatlink();
   s3=comb(s1,s2);
   if(s3==NULL)
   printf("NULL");
   s3=s3->next;
   while(s3!=NULL)
   {
     printf("%d",s3->data);
     s3=s3->next;
     if(s3->next!=NULL)
     {
        printf(" ");
     }
   }
return 0;
}
