#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * add_to_empty(struct node *head , int data);
struct node * add_At_begin(struct node *head , int data);
int main()
{
    struct node *head=NULL;
    head=add_to_empty(head ,787);
    struct node *ptr=head;
    head=add_At_begin(ptr,786);
    ptr=head; 
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
    return 0;
}
struct node * add_to_empty(struct node *head , int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node * add_At_begin(struct node *ptr, int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=ptr;
    ptr->prev=temp;
    return temp;
}
