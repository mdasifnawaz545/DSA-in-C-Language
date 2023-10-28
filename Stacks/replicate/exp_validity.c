// WAP to check whether an expression is valid or not.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
char stack[M];
int top=-1;
void push(char c);
char pop();
int match(char a,char b);
int validate(char ex[]);
int main()
{
    char exp[M];
    printf("Enter the Expression : ");
    gets(exp);
    int val;
    val=validate(exp);
    if (val==1)
    {
        printf("Brackets are well balanced.");
    }
    else{
        printf("Brakcets are not well balanced.");
    }
    
    return 0;
}
int validate(char ex[])
{
    char next;
    for (int i = 0; i < strlen(ex); i++)
    {
        if (ex[i] == '('  || ex[i] == '{' || ex[i] == '[')
        {
            push(ex[i]);
        }
        if (ex[i] == ')'  || ex[i] == '}' || ex[i] == ']')
        {
            if (top==-1)
            {
                printf("Right Brackets are more than that of the left brackets.");
                return 0;
            }
            
            char temp=ex[i];
                next=pop();
                if (match(next,temp))
                {
                    
                }
                else return 0;
        }
    }
    if (top==-1)
    {
        return 1;
    }
    else return 0;
    
}
void push(char c){
    top++;
    stack[top]=c;
}
char pop()
{
    char val;
    val = stack[top];
    top--;
    return val;
}
int match(char a,char b)
{
    if (a=='(' && b==')')
    {
        return 1;
    }
    if (a=='[' && b==']')
    {
        return 1;
    }
    if (a=='{' && b=='}')
    {
        return 1;
    }
    return 0;
}