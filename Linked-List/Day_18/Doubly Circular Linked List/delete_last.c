#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct  node * addEmpty(int data);
struct node * addBegin(struct node *tail,int data);
struct node * addLast(struct node *tail,int data);
struct node * addCertain(struct node *tail,int pos,int data);
struct node * delLast(struct node *tail);
int main()
{
    struct node *tail;
    tail=addEmpty(10);
    tail=addBegin(tail,786);
    tail=addLast(tail,20);
    tail=addLast(tail,30);
    tail=addLast(tail,50);
    tail=addLast(tail,60);
    tail=addLast(tail,70);
    tail=addCertain(tail,5,40);
    tail=delLast(tail);
    struct node*p=tail->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    
    return 0;
}
struct  node * addEmpty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    return temp;
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
struct node * addLast(struct node *tail,int data)
{
    struct node *ptr=malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=tail->next;
    ptr->prev=tail;
    tail->next->prev=ptr;
    tail->next=ptr;
    tail=tail->next;
    return tail;

}
struct node * addCertain(struct node *tail,int pos,int data)
{
    struct node * temp=malloc(sizeof(struct node));
    struct node *p=tail->next;
    temp->data=data;
    pos--;
    while (pos!=1)
    {
        p=p->next;
        pos--;
    }
    temp->next=p->next;
    temp->prev=p;
    p->next->prev=temp;
    p->next=temp;
    return tail;
}
struct node * delLast(struct node *tail)
{
    struct node *p=tail->next;
    while (p->next!=tail)
    {
        p=p->next;
    }
    p->next=tail->next;
    tail->next->prev=p;
    free(tail);
    tail=p;
    return tail;
}
