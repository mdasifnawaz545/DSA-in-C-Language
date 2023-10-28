#include<stdio.h>
#include<stdlib.h>
#define M 5
int stack_arr[M];
int top=-1;
void push(int data);
int isFull(int top);
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    return 0;
}
void push(int data)
{
    if (isFull(top))
    {
        printf("\nStack Overflow.\n");
        exit(1);
    }
    else
    {
        top++;
        stack_arr[top]=data;
        printf("%d ",stack_arr[top]);
    }
}
int isFull(int top)
{
    if (top==M-1)
    {
       return 1;
    }
    else return 0;
}