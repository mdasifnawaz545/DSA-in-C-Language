#include<stdio.h>
#include<stdlib.h>
#define M 5
int stack_arr[M];
int top=-1;
void push(int data);
void display();
int isFull(int top);
int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);

    display();
    return 0;
}
void push(int data)
{
    if (isFull(top))
    {
        printf("\nStack Overflow.");
        exit(1);
    }
    else
    {
        top++;
        for (int i = top; i >= 0; i--)
        {
            stack_arr[i+1]=stack_arr[i];
        }
        stack_arr[0]=data;
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
void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    
}