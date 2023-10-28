#include <stdio.h>
#include <string.h>
#define M 100
char stack_arr[M];
int top = -1;
int validate(char ex[]);
int pop();
int match_arr(char a,char b);
void push(char ch);
int main()
{
    char exp[M];
    printf("Enter the expression : ");
    gets(exp);
    int val;
    val = validate(exp);
    if (val == 1)
    {
        printf("Valid Expression.\n");
    }
    else
        printf("Invalid Expression.\n");

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
            if (top==-1)
            {
                printf("Right Bracket is more than that of the Left Bracket.\n");
                return 0;
            }
            else
            {
                char temp = ex[i];
                int pops;
                pops = pop();
                if (!match_arr(temp,pops))
                {
                    printf("Brackets are not Balanced.\n");
                    return 0;
                }
            }
        }
    }
    if (top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int pop()
{
    int val = stack_arr[top];
    top--;
    return val;
}
void push(char ch)
{
    top++;
    stack_arr[top] = ch;
}
int match_arr(char a,char b)
{
    if ( a =='}' && b == '{' )
    {
        return 1;
    }
    
    if ( a ==')' && b == '(' )
    {
        return 1;
    }
    if ( a ==']' && b == '[' )
    {
        return 1;
    }
    return 0;
    
}