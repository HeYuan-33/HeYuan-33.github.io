#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i,j,n,max=1,num=1;

    scanf("%d",&n);
    int a[n],b[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=a[0];

    for(i=0; i<n-1; i++)
    {
        if(a[i+1]>a[i])
        {
            num++;
            if(num>max)
            {
                max=num;
                for(j=0;j<max;j++)
                {
                    b[j]=a[i-j+1];
                }
            }
        }
        else
        {
            num=1;
        }
    }

    for(i=max-1;i>0;i--)
    {
        printf("%d ",b[i]);
    }
    printf("%d",b[0]);

    return 0;
}

