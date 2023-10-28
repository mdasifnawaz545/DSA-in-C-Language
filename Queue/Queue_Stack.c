#include <stdio.h>
#include <stdlib.h>
#define M 5
int s1[M], s2[M];
int top1 = -1, top2 = -1;
void enqueue(int data);
int dequeue();
int pop1();
int pop2();
void push1(int data);
void push2(int data);
void display();
void peek();
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    printf("\n");
    peek();
    int del = dequeue();
    printf("Deleted Element is : %d\n", del);
    del = dequeue();
    printf("Deleted Element is : %d\n", del);
    del = dequeue();
    printf("Deleted Element is : %d\n", del);
    display();
    printf("\n");
    // enqueue(3);
    // enqueue(4);
    // display();
    return 0;
}
void enqueue(int data)
{
    if (top1 == M - 1)
    {
        printf("Stack is Full.");
        exit(1);
    }
    else
        push1(data);
}
int dequeue()
{
    int val;
    if (top1 == -1)
    {
        printf("Queue is Empty.");
        exit(1);
    }
    else
    {

        while (top1 != -1)
        {
            push2(pop1());
        }
        val = pop2();
        while (top2 != -1)
        {
            push1(pop2());
        }
    }
    return val;
}
void push1(int data)
{
    top1++;
    s1[top1] = data;
}
void push2(int data)
{
    top2++;
    s2[top2] = data;
}
int pop1()
{
    int val = s1[top1];
    top1--;
    return val;
}
int pop2()
{
    int val = s2[top2];
    top2--;
    return val;
}
void peek()
{
    printf("The Top Element is : %d\n", s2[top2]);
}
void display()
{

    while (top1 != -1)
    {
        push2(pop1());
    }
    while (top2 != -1)
    {
        printf("%d ", s2[top2]);
        push1(pop2());
    }
}