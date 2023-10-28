#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define M 100
int top = -1;
char infix[M];
char postfix[M];
char stack_arr[M];
void inTOpos(char exp[]);
void push(char c);
char pop();
int isEmpty();
int precedence(char a);
void display(char pr[]);
void result(char postfix[]);
int main()
{
    printf("Enter the Expression : ");
    scanf("%[^\n]s", &infix);
    inTOpos(infix);
    display(infix);
    printf("\n");
    display(postfix);
    int res;
    result(postfix);
    res=pop();
    printf("\n");
    printf("%d",res);
    return 0;
}
void result(char postfix[])
{
    int res;
    int  a, b;
    char symbol;
    for (int i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        
        if (symbol == '^')
        {
            a = pop();
            b = pop();
            res = pow(b,a);
            push(res);
        }
        else if (symbol == '/')
        {
            a = pop();
            b = pop();
            res = b/a;
            push(res);
        }
        else if (symbol == '*')
        {
            a = pop();
            b = pop();
            res = b*a;
            push(res);
        }
        else if (symbol == '+')
        {
            a = pop();
            b = pop();
            res = a + b;
            push(res);
        }
        else if (symbol == '-')
        {
            a = pop();
            b = pop();
            res = b-a;
            push(res);
        }
        else
        {
            push(symbol - '0');
        }
    }
    
}
void display(char pr[])
{
    for (int i = 0; i < strlen(pr); i++)
    {
        printf("%c", pr[i]);
    }
}
void inTOpos(char exp[])
{
    char symbol, next;
    int j = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        symbol = exp[i];
        if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while ((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
        }
        else if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
        {
            while (!isEmpty() && precedence(stack_arr[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else
            postfix[j++] = symbol;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void push(char c)
{
    if (top == M - 1)
    {
        printf("Stack Overflowed.");
        exit(1);
    }
    top++;
    stack_arr[top] = c;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack Under flowed.");
        exit(1);
    }
    char val;
    val = stack_arr[top];
    top--;
    return val;
}
int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    if (a == '/' || a == '*')
    {
        return 2;
    }
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else
        return 0;
}