#include<stdio.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct sqlist{
    ElemType *elem;
    int length;
};
 void ListInsert_sq(sqlist &L,int i, ElemType e)
{

if(i<1||i>L.length+1) 
 return L;
 if(L.length==MAXSIZE)
 return L;
 for(int j=L.length-1;j>=i-1;j--)
    { L.elem[j+1]=L.elem[j];}
     L.elem[i-1]=e;
     L.length++;
 
 return OK;

} 
/// @brief 
/// @return 
int main()
{
    int i,j;
    j=2;
     sqlist *L1;
     int data;
     for(i=0;i<3;i++)
     {
        scanf("%d",&data);
        L1->elem[i]=data;
     }
    ListInsert_sq(L1,j,j);
    for(i=0;i<4;i++)
    {
        printf("%d",L1->elem[i]);
    }
    return 0;
}
