#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
int top=-1;
int stack_arr[M];
void prime (int n);
void push(int n);
int main()
{
    int n;
    printf("Enter Number : ");
    scanf("%d",&n);
    prime(n);
    return 0;
}
void prime (int n)
{
    int count=0;
        for (int i = 2; i <= n; i++)
        {
            if (n%i==0)
            {
                count++;
            }
            
        }
    if (count==1)
    {
       push(n);
    }
    else 
    printf("Not a Prime number.");
    
}
void push(int n)
{
    if (top==M-1)
    {
        printf("Stack Overflow.");
        exit(1);
    }
    
    top++;
    stack_arr[top]=n;
    printf("%d ",stack_arr[top]);
}