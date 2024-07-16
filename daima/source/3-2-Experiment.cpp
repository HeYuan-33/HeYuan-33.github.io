#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000
int main()
{
    char stack[1000];
    char ch;
    int length=0;
    printf("please enter characters\n");
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='#')
        {
            if(length>0)
            stack[length-2]='\0'; //perform backspace operation
            else
            printf("Unable to perform backspace operation\n");
        }
        else if(ch=='@')
        {
            length=0;//Clear the current line
            stack[length]='\0';
            printf("The current line has been cleared\n");
        }
        else 
        {
            stack[length++]=ch;//Add characters
            stack[length]='\0';
            
        }
         printf("The current line content is:%s\n",stack);
    }
}
