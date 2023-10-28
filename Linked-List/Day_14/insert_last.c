#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_last(struct node *head,int data);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=786;
    head->next=NULL;
    struct node *ptr=head;
    ptr=add_last(ptr,100);
    ptr=add_last(ptr,200);
    ptr=head;
    // head=add_last(head,100);
    // head=add_last(head,100);
    // head=add_last(head,100);
    // head=add_last(head,100);
    // struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}
struct node *add_last(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    head->next=temp;
    temp->prev=head;
    return head;

}