#include<stdio.h>

int main()
{
    int i,n,j,tmp;
    int a[10];
    n=10;
    for(i=0;i<10;i++)
    {
        a[i]=i;
    }
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            if(a[j]>a[j+1])
                   {
                    tmp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                   }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}