#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 10 
int stack_arr[M];
int top=-1;
void decBin(int n);
void push(int data);
void display();
int main()
{
    int n;
    printf("Decimal to Binary\n");
    printf("Enter the number : ");
    scanf("%d", &n);
    decBin(n);
    display();
    return 0;
}
void decBin(int n)
{
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            push(0);
            n = n / 2;
        }
        else
        {
            push(1);
            n = n / 2;
        }
    }
    push(1);
}
void push(int data)
{
    if (top==M-1)
    {
        printf("\nStack Overflow.\n");
        exit(1);
    }
    top++;
    stack_arr[top]=data;
    
}
void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ",stack_arr[i]);
    }
    
}