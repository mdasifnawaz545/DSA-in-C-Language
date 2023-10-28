// infix to postfix;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
void inTOpos(char in[]);
int stack[M];
void push(char c);
char pop();
int precedence(char s);
int IsEmpty();
void result(char pos[]);
char infix[M];
char postfix[M];
int top = -1;
int main()
{
    printf("Enter the expression : ");
    gets(infix);
    inTOpos(infix);
    puts(postfix);
    result(postfix);
    int res;
    res=pop();
    printf("%d ",res);
    return 0;
}
void result(char pos[])
{
    char symbol;
    char a,b,next;
    int res;
    for (int i = 0; i < strlen(pos); i++)
    {
        symbol=pos[i];
        switch (symbol)
        {
        case '^':
            a=pop();
            b=pop();
            res=pow(b,a);
            push(res);
            break;
        
        case '/':
            a=pop();
            b=pop();
            res=b/a;
            push(res);
            break;
        
        case '*':
            a=pop();
            b=pop();
            res=b*a;
            push(res);
            break;
        
        case '+':
            a=pop();
            b=pop();
            res=b+a;
            push(res);
            break;
        
        case '-':
            a=pop();
            b=pop();
            res=b-a;
            push(res);
            break;
        
        default:
        push(symbol - '0');
            break;
        }
    }
    
}
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void push(char c)
{
    top++;
    stack[top] = c;
}
char pop()
{
    int topp = stack[top];
    top--;
    return topp;
}
void inTOpos(char in[])
{
    char symbol;
    char a, b, next;
    int j = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        symbol = in[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
            break;

        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while (!IsEmpty() && precedence(stack[top]) >= precedence(symbol))
                
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;

        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while (top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int precedence(char s)
{
    switch (s)
    {
    case '^':
        return 5;
        break;
    case '/':
    case '*':
        return 4;
        break;
    case '+':
    case '-':
        return 3;
        break;

    default:
        return 0;
        break;
    }
}