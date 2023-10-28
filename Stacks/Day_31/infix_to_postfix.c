#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
int top = -1;
int stack[MAX];
char infix[MAX];
char postfix[MAX];
void inTopost(char in[]);
void push(char c);
char pop();
void dispaly();
void result(char r[]);
int isEmpty();
int calculate(char a, char b);
int precedence(char operand);
int main()
{
    printf("Enter the Expression : ");
    gets(infix);
    inTopost(infix);
    dispaly();
    result(postfix);
    int res=pop();
    printf("%d",res);
    return 0;
}
void inTopost(char in[])
{
    char symbol, next;
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

        case '*':
        case '/':
        case '^':
        case '+':
        case '-':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void result(char r[])
{
    int symbol;
    int a, b, next;
    int res;

    for (int i = 0; i < strlen(r); i++)
    {

        symbol = r[i];
        switch (symbol)
        {
        case '^':
            a = pop();
            b = pop();
            res=pow(b,a);
            push(res);
            break;
        case '/':
            a = pop();
            b = pop();
            res=b/a;
            push(res);
            break;
        case '*':
            a = pop();
            b = pop();
            res=b*a;
            push(res);
            break;
        case '+':
            a = pop();
            b = pop();
            res=b+a;
            push(res);
            break;
        case '-':

            a = pop();
            b = pop();
            res=b-a;
            push(res);
            break;

        default:
            push(symbol-'0');
            break;
        }
    }
}
int calculate(char a, char b)
{
}
int precedence(char operand)
{
    switch (operand)
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
    }
}
void dispaly()
{
    puts(postfix);
}
void push(char c)
{
    top++;
    stack[top] = c;
}
char pop()
{
    int val = stack[top];
    top--;
    return val;
}