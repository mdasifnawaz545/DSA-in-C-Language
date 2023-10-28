#include <stdio.h>
#include <stdlib.h>
#define M 10
int stack_arr[M];
void prime(int n);
void push(int data);
int top = -1;
void display();
int main()
{
    int n;
    printf("Prime Factorization\n");
    printf("Enter the number : ");
    scanf("%d", &n);
    prime(n);
    display();
    return 0;
}
void display()

{
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
}
void prime(int n)
{
    int i = 2;
    while (n != 1)
    {

        while (n % i == 0)
        {
            push(i);
            n = n / i;
        }
        i++;
    }
}

void push(int data)

{
    if (top == M - 1)
    {
        printf("\nStack overflow.\n");
        exit(1);
    }
    top++;
    stack_arr[top] = data;
    // printf("%d ",stack_arr[top]);
}