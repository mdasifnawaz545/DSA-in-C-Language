#include<stdio.h>
#include<stdlib.h>
#define M 10
int stack_arr[M];
int top=-1;
void prime(int n);
void push(int n);
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    prime(n);
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    
    return 0;
}
void prime(int n)
{
    int i=2;
    while (n!=1)
    {
        while (n%i==0)
        {
            push(i);
            n=n/i;
        }
        i++;
    }
    
}
void push(int n)
{
    if (top==M-1)
    {
        printf("Stack Overflow.");
        exit(1);
    }
    else{
    top++;
    stack_arr[top]=n;
    }
}

