#include<stdio.h>
int main()
{
    char a[1000],stack[1000];
    int t=-1,top=-1;
    char ch1;
     //intput symbol
    while(1) 
    {
     scanf("%c",&ch1);
     a[++t]=ch1;
     if(a[t]=='\n'&&t>=1&&a[t-1]=='.')
     break;
    }
    for(int i=0;i<t;i++)
    {
        //push '(','[','{'
        if(a[i]=='('||a[i]=='{'||a[i]=='[')
        stack[++top]=a[i];  
        
        //find macthing symbol
        else if(a[i]==')')
        {

            if(top==-1)
            {
                printf("NO\n");
                break;
            }

            else 
            {
                if(stack[top]=='(')
                 top--;
                 else
                 {
                    printf("NO");
                    break;
                 }          
            }   
        }
         else if(a[i]==']')
        {
            if(top==-1)
            {
                printf("NO\n");
                break;
            }

            else 
            {
                if(stack[top]=='[')
                 top--;
                 else
                 {
                    printf("NO\n");
                    break;
                 }
            }  
        }
         else if(a[i]=='}')
        {
            if(top==-1)
            {
                printf("NO\n");
                break;
            }
            else 
            {
                if(stack[top]=='{')
                 top--;
                 else
                 {
                    printf("NO\n");
                    break;
                 }
            }
        }
        else
        printf("");
    }
    if(top!=-1)
    {
        printf("NO");
    }
    else
    printf("YES");
}