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
int main()
{
    struct node *head=NULL;
    int data;
    struct node *ptr=head;
    ptr=add_empty(ptr,10);
    head=add_begin(ptr,786);
    ptr=add_last(ptr,20);
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
    struct node *temp=malloc(sizeof(struct node ));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return temp;
}
struct node * add_begin(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
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
    struct node *ptr1=head;
    while (ptr1->next=NULL)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=temp;
    temp->prev=ptr1;
    return temp;
}