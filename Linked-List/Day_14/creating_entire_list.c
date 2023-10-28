#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_to_empty(struct node *head , int data);
struct node *add_last(struct node *head , int data);
int main()
{
    struct node *head=NULL;
    head=add_to_empty(head,786);
    struct node *ptr=head;
    ptr=add_last(ptr,10);
    ptr=add_last(ptr,20);
    ptr=add_last(ptr,30);
    ptr=add_last(ptr,40);
    ptr=add_last(ptr,50);
    ptr=add_last(ptr,60);
    ptr=add_last(ptr,70);
    ptr=add_last(ptr,80);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}
struct node *add_to_empty(struct node *head , int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node *add_last(struct node *head , int data)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
    return temp;
}