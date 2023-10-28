#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define M 100
int stack[M];
char infix[M];
char postfix[M];
char pop();
void result(char pos[]);
void push(char c);
int IsEmpty();
int precedence(char operand);
int top = -1;
void inTOpos(char in[]);
void display(char c[]);
int main()
{
    printf("Enter the Expression : ");
    gets(infix);
    inTOpos(infix);
    display(postfix);
    int res;
    result(postfix);
    res = pop();
    printf("%d", res);
    return 0;
}
void result(char pos[])
{
    char symbol;
    int a, b, res;
    for (int i = 0; i < strlen(pos); i++)
    {
        symbol = pos[i];
        if (symbol == '^')
        {
            a = pop();
            b = pop();
            res = pow(b, a);
            push(res);
        }
        else if (symbol == '/')
        {
            a = pop();
            b = pop();
            res = b / a;
            push(res);
        }
        else if (symbol == '*')
        {
            a = pop();
            b = pop();
            res = b * a;
            push(res);
        }
        else if (symbol == '+')
        {
            a = pop();
            b = pop();
            res = b + a;
            push(res);
        }
        else if (symbol == '-')
        {
            a = pop();
            b = pop();
            res = b - a;
            push(res);
        }
        else
        {
            push(symbol - '0');
        }
    }
}
void display(char c[])
{
    for (int i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
    }
}
void inTOpos(char in[])
{
    int symbol, next, j = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        symbol = in[i];
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
        else if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        {
            while (!IsEmpty() && precedence(stack[top]) >= precedence(symbol))
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
int precedence(char operand)
{
    switch (operand)
    {
    case '^':
        return 5;
        break;
    case '*':
    case '/':
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
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
char pop()
{
    char cal;
    cal = stack[top];
    top--;
    return cal;
}
void push(char c)
{
    top++;
    stack[top] = c;
}