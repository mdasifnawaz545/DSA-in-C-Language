#include<stdio.h>
#include<stdlib.h>
#define M 5
int top=-1;
int stack_arr[M];
void push(int data);
void pushTop(int data);
int main()
{
    push(1);   
    push(2);   
    push(3);   
    push(4);   
    pushTop(786);  
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",stack_arr[i]);
    }
     
    return 0;
}
void push(int data)
{
    if (top==M-1)
    {
       printf("\nStack Overflow.\n");
       exit(1);
    }
    else{
        top++;
        stack_arr[top]=data;
        // printf("%d ",stack_arr[top]);
    }
}
void pushTop(int data)
{
    for (int i = top; i >=0; i--)
    {
        stack_arr[i+1]=stack_arr[i];
    }
    stack_arr[0]=data;
    top++;
}
