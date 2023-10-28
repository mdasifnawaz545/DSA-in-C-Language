#include <stdio.h>
#include <stdlib.h>
#define M 5
int front = -1;
int rear = -1;
int queue[M];
void enqueue(int data);
void dequeue();
void peek();
void display();
int main()
{
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    peek();
    return 0;
}
void enqueue(int data)
{
    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        queue[rear] = data;
    }
    else if ((rear + 1) % M == front)
    {
        printf("Queue is Full.\n");
        exit(1);
    }
    else
    {
        rear = (rear + 1) % M;
        queue[rear] = data;
    }
}
void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("\nDeleted Element is : %d\n", queue[front]);
        front = (front + 1) % M;
    }
}
void peek()
{
    printf("\nPeek Element is : %d\n",queue[front]);
}
void display()
{
    printf("Queue is : ");
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % M;
    }while(i!=rear);
    printf("%d",queue[i]);
}