#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
int queue[M];
int front = -1;
int rear = -1;
void enqueue(int data);
int dequeue();
void display();
void peek();
int main()
{
    enqueue(1);
    printf("\n");
    enqueue(2);
    printf("\n");
    enqueue(3);
    printf("\n");
    display();
    printf("\n");
    peek();
    printf("\n");
    dequeue();
    printf("\n");
    peek();
    printf("\n");
    display();
    return 0;
}
void enqueue(int data)
{
    if (rear == M - 1)
    {
        printf("Queue is Full.");
    }
    else if (rear == -1 && front == -1)
    {
        rear = front = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}
int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty.");
    }
    else if (front == rear)
    {
        printf("%d ", queue[front]);
    }
    else
    {
        printf("%d ", queue[front]);
        front++;
    }
}
void display()
{
    for (int i = front; i < rear + 1; i++)
    {
        printf("%d ", queue[i]);
    }
}
void peek()
{
    printf("%d ", queue[front]);
}