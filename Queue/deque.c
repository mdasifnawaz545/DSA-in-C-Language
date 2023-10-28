#include <stdio.h>
#include <stdlib.h>
#define M 5
int a[M];
int rear = -1;
int front = -1;
int isFull();
void enqueueFront(int data);
void dequeueFront();
void enqueueRear(int data);
void dequeueRear();
void display();
void peek();
int main()
{
    enqueueFront(2);
    enqueueFront(1);
    enqueueRear(3);
    enqueueRear(4);
    enqueueFront(999);
    dequeueRear();
    dequeueFront();
    display();
    return 0;
}
void peek()
{
    printf("Peek Element : %d",a[front]);
}
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (rear == M - 1 && front == 0)
    {
        return 1;
    }
    else
        return 0;
}
void enqueueFront(int data)
{
    if (isFull())
    {
        printf("Queue is Full.");
        exit(1);
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        a[front] = data;
    }
    else if (front == 0)
    {
        front = M - 1;
        a[front] = data;
    }
    else
    {
        front--;
        a[front] = data;
    }
}
void dequeueFront()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is Empty.");
    }
    else if (front == rear)
    {
        printf("Deleted Element is : %d\n", a[front]);
        front = rear = -1;
    }
    else if (front == M - 1)
    {
        printf("Deleted Element is : %d\n", a[front]);
        front = 0;
    }
    else
    {
        printf("Deleted Element is : %d\n", a[front]);
        front++;
    }
}
void enqueueRear(int data)

{
    if (isFull())
    {
        printf("Queue is Full.");
        exit(1);
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        a[rear] = data;
    }
    else if (rear == M - 1)
    {
        rear = 0;
        a[rear] = data;
    }
    else
    {
        rear++;
        a[rear] = data;
    }
}
void dequeueRear()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is Empty.");
        exit(1);
    }
    else if (rear == front)
    {
        printf("Deleted Element is : %d\n", a[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Deleted Element is : %d\n", a[rear]);
        rear = M - 1;
    }
    else
    {
        printf("Deleted Element is : %d\n", a[rear]);
        rear -- ;
    }
}
void display()
{
    int i=front;
    printf("Queue is : ");
    do
    {
        printf("%d ",a[i]);
        i=(i+1)%M;
    } while (i!=rear);
        printf("%d ",a[i]);
    
}