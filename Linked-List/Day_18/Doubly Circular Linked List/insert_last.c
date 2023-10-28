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
int main()
{
    struct node *tail;
    tail=addEmpty(10);
    tail=addBegin(tail,786);
    tail=addLast(tail,20);
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
