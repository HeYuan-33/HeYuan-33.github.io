#include<stdio.h>
int main()
 {
   int a[2000000];
    int count=0,b,i=0,num=0;
     while(count!=2)
    {
      scanf("%d",&b);
      if(b==-1)
          count++;
      else 
      {
       a[i++]=b;
          num++;
       }
 }
     for(int i=0;i<num-1;i++)
   {
     for(int j=0;j<num-i-1;j++)
   {
      if(a[j]>a[j+1])
      {
        int c=a[j];
        a[j]=a[j+1];
        a[j+1]=c;
             }
                  }
                          }
     for(int i=0;i<num;i++)
     {
         if(i==0)
             printf("%d",a[i]);
        else 
            printf(" %d",a[i]);
     }
      if(num==0)printf("NULL");
      return 0;
}
