#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
void reverse(struct node *head);
struct node *add(struct node *head,int data);
struct node *add_begin(struct node *head,int data);
int main()
{
    struct node *head=NULL;
    head=add(head,10);
    int data=20;
    head=add_begin(head,data);
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    reverse(ptr);
    return 0;
}
struct node *add_begin(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node *add(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
void reverse(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    
}