#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 5
int stack_arr[M];
int top = -1;
int pop();
void push(int data);
int IsEmpty();
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int del;
    del = pop();
    printf("\nDeleted Element is %d ", del);
    return 0;
}
void push(int data)
{
    if (top == M - 1)
    {
        printf("Stack Overflow.\n");
        exit(1);
    }
    else
    {
        top++;
        stack_arr[top] = data;
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
int pop()
{
    if (IsEmpty())
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    else
    {
        int value = stack_arr[0];
        for (int i = 0; i <= top; i++)
        {
            stack_arr[i] = stack_arr[i + 1];
        }
        return value;
    }
}