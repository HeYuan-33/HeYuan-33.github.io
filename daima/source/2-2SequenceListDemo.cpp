#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define InitMix 100

typedef struct 
{
    int *data;
    int length;
}List;
void Initlist(List &l)
{
     l.data=(int *)malloc(100*sizeof(int));
     l.length=0;
}
void CreatList(List &l)
{
    printf("please input L length");
    scanf("%d",&l.length);
    printf("please input ");
    for(int i=0;i<l.length;i++)
    {
       scanf("%d",&l.data[i]);
    }
}
void MergeList(List la,List lb,List &lc)
{
    lc.length=la.length+lb.length;
    lc.data=(int *)malloc(100*sizeof(int));
    int  *pc,*pa,*pb,*p1,*p2;
    pc=lc.data;
    pa=la.data;
    pb=lb.data;
    p1=la.data+la.length-1;
    p2=lb.data+lb.length-1;
    while(pa<=p1&&pb<=p2)
    {
        if(*pa<=*pb) 
        *pc++=*pa++;
        else *pc++=*pb++;
    }
    while(pa<=p1) *pc++=*pa++;
    while(pb<=p2) *pc++=*pb++;

}
int main()
{
    List la,lb,lc;
    Initlist(la);
    Initlist(lb);
    CreatList(la);
    CreatList(lb);
    MergeList(la,lb,lc);
    for(int i=0;i<lc.length;i++)
    {
        printf("%d ",lc.data[i]);
    }
}