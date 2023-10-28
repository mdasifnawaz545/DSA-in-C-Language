#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * add_empty(struct node *head,int data);
struct node * add_begin(struct node *head,int data);
struct node * add_last(struct node *head,int data);
struct node * add_certain(struct node *head,int pos,int data);
int main()
{
    struct node *head=NULL;
    struct node *ptr;
    head=add_empty(head,10);
    head=add_begin(head,786);
    // head=add_begin(head,786);
    ptr=add_last(head,20);
    ptr=add_last(head,30);
    ptr=add_last(head,50);
    ptr=add_last(head,60);
    ptr=add_last(head,70);
    ptr=add_certain(head,5,40);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}
struct node * add_empty(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head=temp;
    return head;
}
struct node * add_begin(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node ));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node * add_last(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node *ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    // ptr=head;
    return temp;
}
struct node * add_certain(struct node *head,int pos,int data)
{
    struct node *temp=malloc(sizeof (struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node *ptr=head;
    pos--;
    while (pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
    ptr=ptr->next->next;
    ptr->prev=temp;
    ptr=head;
    return ptr;
}
