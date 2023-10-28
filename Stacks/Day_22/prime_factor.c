#include <stdio.h>
#define M 5
int stack_arr[M];
int rem;
int top = -1;
void prime(int data);
void push(int data);
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    prime(n);
    return 0;
}
void prime(int data)
{
    int i=2;
   while (data!=1)
   {
    while (data%i==0)
    {
        push(i);
        data=data/i;
    }
    i++;
   }
   
}
void push(int data)
{
    top++;
    stack_arr[top] = data;
    printf("%d ", stack_arr[top]);
}