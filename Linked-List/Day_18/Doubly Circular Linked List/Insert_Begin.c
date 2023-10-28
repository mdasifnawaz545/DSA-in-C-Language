#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * addEmpty(int data);
struct node * addBegin(struct node *tail,int data);
int main()
{
    struct node *tail;
    tail=addEmpty(10);
    tail=addBegin(tail,786);
    struct node *p=tail->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    
    return 0;
}
struct node * addEmpty(int data)
{
    struct node *p=malloc(sizeof(struct node));
    p->data=data;
    p->next=p;
    p->prev=p;
    return p;
}
struct node * addBegin(struct node *tail,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=tail->next;
    temp->prev=tail;
    tail->next->prev=temp;
    tail->next=temp;
    return tail;
}