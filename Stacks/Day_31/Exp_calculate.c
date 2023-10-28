#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define M 100
int top = -1;
int stack[M];
char infix[M];
char postfix[M];
void inTOpos(char in[]);
void push(char c);
char pop();
void display();
int precedence(char operand);
void result(char pos[]);
int isEmpty();
int main()
{
    printf("Enter the Expression : ");
    gets(infix);
    inTOpos(infix);
    display();
    result(postfix);
    printf("\n");
    int res=pop();
    printf("%d", res);
    return 0;
}
void inTOpos(char in[])
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

        case '^':
        case '/':
        case '*':
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
            break;
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void result(char pos[])
{
    char symbol;
    int a, b, res;
    for (int i = 0; i < strlen(pos); i++)
    {
        symbol = pos[i];
        switch (symbol)
        {
        case '^':
            a = pop();
            b = pop();
            res = pow(b, a);
            push(res);
            break;

        case '/':
            a = pop();
            b = pop();
            res = b / a;
            push(res);
            break;

        case '*':
            a = pop();
            b = pop();
            res = b * a;
            push(res);
            break;

        case '+':
            a = pop();
            b = pop();
            res = b + a;
            push(res);
            break;

        case '-':
            a = pop();
            b = pop();
            res = b - a;
            push(res);
            break;

        default:
        push(symbol - '0');
            break;
        }
    }
}
void push(char c)
{
    if (top == M - 1)
    {
        printf("Stack Overflowed.");
        exit(1);
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflowed.");
    }
    int exp = stack[top];
    top--;
    return exp;
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int precedence(char operand)
{
    switch (operand)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;

        return 0;
    }
}
void display()
{
    for (int i = 0; i < strlen(postfix); i++)
    {
        printf("%c", postfix[i]);
    }
}