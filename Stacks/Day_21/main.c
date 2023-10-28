#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack_arr[N];
int choice, data, top = -1;
void push(int data);
int pop();
int main()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Print all the elements of the stack\n");
    printf("5. Quit\n");
    while (1)
    {
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the element : ");
            scanf("%d", &data);
            push(data);
        }
        else if (choice == 2)
        {
            int del;
            del = pop();
            printf("The Deleted element is : %d\n", del);
        }
        else if (choice == 3)
        {
            printf("The Top most element is : %d\n", stack_arr[top]);
        }
        else if (choice == 4)
        {
            printf("The Elements are : ");
            for (int i = 0; i <= top; i++)
            {
                printf("%d ", stack_arr[i]);
            }
            printf("\n");
        }
        else if (choice == 5)
        {
            exit(1);
        }
    }

    return 0;
}
void push(int data)
{
    if (top == N - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflowed\n");
        exit(1);
    }
    int value;
    value = stack_arr[top];
    top--;
    return value;
}