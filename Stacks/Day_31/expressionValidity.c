#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
int validate(char ex[]);
void push(char c);
char pop();
int match_arr(char a, char b);
int main()
{
    char exp[MAX];
    printf("Enter the Expression : ");
    gets(exp);
    int bal;
    bal = validate(exp);
    if (bal == 1)
    {
        printf("Valid Expression.\n");
    }
    else    printf("Invalid Expression.\n");
     

    return 0;
}
int validate(char ex[])
{
    for (int i = 0; i < strlen(ex); i++)
    {
        if (ex[i] == '(' || ex[i] == '{' || ex[i] == '[')
        {
            push(ex[i]);
        }
        else if (ex[i] == ')' || ex[i] == '}' || ex[i] == ']')
        {
            if (top == -1)
            {
                printf("Right Brackets are more.\n");
                return 0;
            }
            else
            {
                char temp;
                temp = pop();
                if (!match_arr(ex[i], temp))
                {
                    printf("Brackets are balaced.\n");
                }
            }
        }
    }
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int match_arr(char a, char b)
{
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack is overflowed.\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        exit(1);
    }
    char val = stack[top];
    top--;
    return val;
}