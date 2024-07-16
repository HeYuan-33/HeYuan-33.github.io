#include<stdio.h>
#include<stdlib.h>
struct xu{
    int data;
    struct xu *next;
};
struct xu* creat()
{
    int t;
    struct xu *head,*q,*p;
    scanf("%d",&t);
    head=(struct xu*)malloc(sizeof(struct xu));
    q=head;
    while(t!=-1)
    {
        p=(struct xu*)malloc(sizeof(struct xu));
        p->data=t;
        q->next=p;
        q=p;
        scanf("%d",&t);
    }
    q->next=NULL;
    return head;
}
struct xu* comb(struct xu *head1,struct xu *head2){
    struct xu *p1,*p2,*head,*p3;
    head=(struct xu*)malloc(sizeof(struct xu));
    p1=head1->next;
    p2=head2->next;
    p3=head;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            p3->next=p1;
            p3=p1;
            p1=p1->next;
        }
        if(p1->data>p2->data)
        {
            p3->next=p2;
            p3=p2;
            p2=p2->next;
        }
    }
    if(p1!=NULL)
        p3->next=p1;
    else if(p2!=NULL)
        p3->next=p2;
    head1->next=NULL;
    head2->next=NULL;
    return head;
}
int main()
{
    struct xu *s1,*s2,*s3;
    s1=creat();
    s2=creat();
    s3=comb(s1,s2);
    s3=s3->next;
    if(s3==NULL)
    {
        printf("NULL");
    }
    if(s3!=NULL)
    {
        printf("%d",s3->data);
        s3=s3->next;
        if(s3!=NULL)
        {
            printf(" ");
        }
    }
    return 0;
}




