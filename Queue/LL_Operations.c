#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
void enqueue(int data);
void dequeue();
void peek();
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    printf("\n");
    peek();
    rear=front;
    struct node *ptr = rear;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
void enqueue(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (rear == NULL && front == NULL)
    {
        rear=front=temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void dequeue()
{
    struct node *del = front;
    front = front->next;
    free(del);
    del = front;
}
void peek()
{
    struct node *temp=front;
    printf("Peek Element is : %d\n",temp->data);
}