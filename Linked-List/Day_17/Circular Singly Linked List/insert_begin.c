// Insertion of a node at the beginning of the singly circular linked list.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * add_empty(int data);
struct node * add_begin(struct node *head,int data);
int main()
{
    struct node *tail;
    tail=add_empty(10);
    tail=add_begin(tail,786);
    struct node *p=tail;
    p=p->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    
    return 0;
}
struct node * add_empty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node * add_begin(struct node *head,int data)
{
    struct node * temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head->next;
    head->next=temp;
    return head;
}