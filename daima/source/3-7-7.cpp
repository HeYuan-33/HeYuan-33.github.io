#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30

typedef struct snode
{
    double data1;
    struct snode *next;
}StackNode,*LinkStack;

LinkStack top=NULL;

LinkStack PushStack(double x)
{
    StackNode *p1;
    p1=(StackNode *)malloc(sizeof(StackNode));
    p1->data1=x;
    p1->next=top;
    top=p1;
    return top;
}

double PopStack()
{
    double t;
    StackNode *p1;
    if(top==NULL) return 0;
    else{
    t=top->data1;
    p1=top;
    top=top->next;
    free(p1);
    return t;
    }
}

double calcul(double a1,double b1,char c1)
{
    switch(c1)
    {
    case '+':
        return a1+b1;
    case '-':
        return b1-a1;
    case '*':
        return a1*b1;
    case '/':
        return b1/a1;
    default :
        return 0;
    }
}

int Empty_SeqStack()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

char *revstr(char *strlen, int len1)
{

    char    *start = strlen;
    char    *end = strlen + len1 - 1;
    char    ch1;

    if (strlen != NULL)
    {
        while (start < end)
        {
            ch1 = *start;
            *start++ = *end;
            *end-- = ch1;
        }
    }
    return strlen;
}
int main()
{
    char s[N];
    gets(s);
    char temp[N];
    char *strrevtemp;
    int i;
    int j=-1;
    double a,b,result;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]!=' ')
        {
            if(s[i-1]==' '||i==0)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                     PushStack(s[i]-'0');
                     i--;
                }
                else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                        if(!Empty_SeqStack())
                            a=PopStack();
                        else{
                            printf("ERROR");
                            return 0;
                        }
                        if(!Empty_SeqStack())
                            b=PopStack();
                        else{
                            printf("ERROR");
                            return 0;
                        }
                    if(s[i]=='/'&&b==0)
                    {
                        printf("ERROR");
                        return 0;
                    }
                    result=calcul(b,a,s[i]);
                    PushStack(result);
                }
                else{
                    printf("ERROR");
                    return 0;
                }
            }
            else{
                j=0;
                while(s[i]!=' '&&i>=0)
                    temp[j++]=s[i--];
                temp[j]='\0';
                if(strlen(temp)<=1)
                {
                    printf("ERROR");
                    return 0;
                }
                strrevtemp=revstr(temp,strlen(temp));
                PushStack(atof(strrevtemp));
                i++;

            }
        }
    }
        if(top!=NULL)
        printf("%.1lf",top->data1);
        else
            printf("ERROR");
        return 0;
}