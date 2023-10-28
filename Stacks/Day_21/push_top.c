#include <stdio.h>
#define M 5
int top = -1;
int stack_arr[M];
void push(int data);
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    for (int i = 0; i < M; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    
    return 0;
}
void push(int data)
{
    if (top == M - 1)
    {
        printf("\nStack Overflow.\n");
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