#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * add_last(struct node *head,int data);
struct node* add(struct node *head);
struct node* add_certain(struct node *head,int pos,int data);
int main()
{
    struct node *head=NULL;
    head=add(head);
    struct node *ptr=head;
    ptr=add_last(ptr,10);
    ptr=add_last(ptr,20);
    ptr=add_last(ptr,40);
    ptr=head;
    ptr=add_certain(ptr,4,30);
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}
struct node* add(struct node *head)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=786;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node * add_last(struct node *head,int data)
{
    struct node *ptr=head;
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=ptr;
    ptr->next=temp;
    temp->data=data;
    return temp;

}
struct node* add_certain(struct node *head,int pos,int data)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
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
