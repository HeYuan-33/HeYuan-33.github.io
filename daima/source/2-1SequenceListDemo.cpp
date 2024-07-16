#include<stdio.h>
#include<stdlib.h>
#define ERROR 0

typedef int Status;
typedef int Elemtype;
typedef struct{
    int  *data;
    int length;
}List;
 Status InitList(List &L)
{
    L.data=(int *)malloc(100*sizeof(int));
    L.length=0;
}
Status Listlength(List l)
{
    return l.length;
}
 Status GetElem(List l,int i,int &e)
{
      e=l.data[i];
}

 Status Locate(List l,int e)
{
    int i;
    for(i=0;i<l.length;i++)
    {
    	if(l.data[i]==e)
    	return i+1;
	}
    	return 0; 
}
void ListInsert(List &L, int i, int e) {
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
} 
Status CreatList( List &L)
{
    int i;
    scanf("%d",&L.length);
    for(i=0;i<L.length;i++)
    {
    	scanf("%d",&L.data[i]);
	}
}
Status unionList(List &la,List lb)
{
    int i,e;
    int la_len=Listlength(la);
    int lb_len=Listlength(lb);
  for(i=0;i<lb_len;i++)
  {
    GetElem(lb,i,e);
    if(Locate(la,e)==0)
    {
        ListInsert(la,++la_len,e);
    }
  }
}
int main()
{
    List la,lb;
    int i,len;
    InitList(la);
    InitList(lb);
    CreatList(la);
    CreatList(lb);
    unionList(la,lb);
    len=Listlength(la);
    for(i=0;i<len;i++)
    {
        printf("%d ",la.data[i]);
    }
    return 0;
}
