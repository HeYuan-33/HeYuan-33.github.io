#include<stdio.h>
#include<stdlib.h>

int main()
{
    char s[10000],stack[10000];
    char c1,c2;
    int top=-1,pos=-1;
    while(1)
    {
      scanf("%c",&c1);
      if(c1=='.'&&c2=='\n')
      break;
      s[++pos]=c1;
      c1=c2;
    }
    for(int i=0;i<pos;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        stack[++top]=s[i];
        else if(s[i]=='/'&&s[i+1]=='*')
        {stack[++top]='=';
        i++;
        }
        else if(s[i]==']')
        {
            if(top=-1)
            {
                printf("NO\n");
                printf("?-]");
            }
            if(stack[top]=='[')
            top--;
            else
            {
                printf("NO\n");
                if(stack[top]=='=')
                printf("/*-?");
                else
                printf("%c-?",stack[top]);
            }
        }
        
    }
}