#include<stdio.h>
int main()
{
    int s1[100000],s2[100000];
    int n,i,a=0,b=0,c[200000];
    int t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&s2[i]);
    }
    for(i=0;i<2*n;i++)
    {
        if(s1[a]<s2[b])
        {
            c[i]=s1[a];
            a++;
        }
        else
        {
            c[i]=s2[b];
            b++;
        }
    }
    
  
    
        t=c[(2*n-1)/2];
    
    printf("%d",t);
}