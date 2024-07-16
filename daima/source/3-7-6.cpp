#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    char ch1=' ',ch2=' ';
    char s[1000],stack[1000];
    int top=-1,pos=-1;
    while(1)
    {
         scanf("%c",&ch1);
        if(ch1=='.'&&ch2=='\n')
           break;
        s[++pos]=ch1;
        ch2=ch1;
    }
s[pos]='\0';
    for(int i=0;i<pos;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            stack[++top]=s[i];
        }
        else if(s[i]=='/'&&i<pos&&s[i+1]=='*')
        {
            stack[++top]='<';
            i++;
        }

        else if(s[i]=='}')
        {
            if(top==-1)
            {
                printf("NO\n");
                printf("?-}");
                 return 0;
            }
            if(stack[top]=='{')
                top--;
            else
            {
                printf("NO\n");
                if(stack[top]=='<')
                {
                    printf("/*-?");
                }
                else
                {
                    printf("%c-?",stack[top]);
                    return 0;
                }
            }
        }

else if(s[i]==']')
        {
        if(top==-1)
        {
            printf("NO\n");
            printf("?-]");
             return 0;
        }
        if(stack[top]=='[')
            top--;
            else
            {
                printf("NO\n");
            if(stack[top]=='<')
                printf("/*-?");
                else
                    printf("%c-?",stack[top]);
                return 0;
        }
    }
        
        else if(s[i]==')')
        {
            if(top==-1)
            {
                printf("NO\n");
                printf("?-)");
                 return 0;
            }
            if(stack[top]=='(')
                top--;
            else
            {
                printf("NO\n");
                if(stack[top]=='<')
                {
                    printf("/*-?");
                }
                else
                {
                    printf("%c-?",stack[top]);
                    return 0;
                }
            }
        }

          else if(s[i]=='*'&&i<pos&&s[i+1]=='/')
               {
            if(top==-1)
            {
                printf("NO\n");
                printf("?-*/");
                return 0;
            }
            if(stack[top]=='<')
            {
                top--;
                i++;
            }
            else
            {
                printf("NO\n");
                 printf("%c-?",stack[top]);
                return 0;
                }
            }
        else
            printf("");
    }
    if(top!=-1)
    {
        printf("NO\n");
         if(stack[top]=='<')
                {
                    printf("/*-?");
                }
                else
                {
                    printf("%c-?",stack[top]);
                }
    }
        else
        printf("YES");
        return 0;
}




