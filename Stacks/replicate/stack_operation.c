#include<stdio.h>
#include<stdlib.h>
#define M 100
int top=-1;
int stack_arr[M];
void push(int data);
void pushAtFirst(int data);
void popAtFirst();
void display(int stack_arr[]);
int main()
{
    push(1);
    push(2);
    push(3);
    pushAtFirst(0);
    popAtFirst();
    display(stack_arr);
    return 0;
}
void push(int data)
{
    if (top==M-1)
    {
        printf("Stack Overflow.");
        exit(1);
    }
    top++;
    stack_arr[top]=data;
}
void pushAtFirst(int data)
{
    top++;
    for (int i = top; i > 0; i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
void display(int stack_arr[])
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n",stack_arr[i]);
    }
    
}
void popAtFirst()
{
    for (int i = 0; i < top; i++)
    {
        stack_arr[i]=stack_arr[i+1];
    }
    top--;
}