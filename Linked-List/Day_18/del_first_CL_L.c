// Creatig a Singly circular linked list.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addEmpty(int data);
struct node *addBegin(struct node *tail, int data);
struct node *addEnd(struct node *tail, int data);
struct node *addCertain(struct node *tail, int data);
struct node *delFirst(struct node *tail);
int main()
{
    struct node *tail;
    tail = addEmpty(10);
    tail = addBegin(tail, 5);
    tail = addEnd(tail, 20);
    tail = addEnd(tail, 30);
    tail = addEnd(tail, 50);
    tail = addEnd(tail, 60);
    tail = addCertain(tail, 40);
    tail=delFirst(tail);
    struct node *p=tail->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    
    return 0;
}
struct node *addEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *addBegin(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    return tail;
}
struct node *addEnd(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next=tail->next;
    tail->next=temp;
    tail=tail->next;
    return tail;
}
struct node *addCertain(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    int pos=5;
    // printf("Enter the Position : ");
    // scanf("%d",&pos);   
    struct node *p=tail->next; 
    pos--;
    while (pos!=1)
    {
        p=p->next;
        pos--;
    }
    temp->next=p->next;
    p->next=temp;
    if (p==tail)
    {
        tail=tail->next;
    }
    return tail;
}
struct node *delFirst(struct node *tail)
{
    struct node *p=tail->next;
    tail->next=p->next;
    free(p);
    p=NULL;
    return tail;
}
