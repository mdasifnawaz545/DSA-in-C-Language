#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * insertSort(struct node *head,int data);
int main()
{
    struct node*head=malloc(sizeof(struct node));
    head->data=786;
    head->next=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=10;
    current->next=NULL;
    head->next=current;

    current=malloc(sizeof(struct node));
    current->data=20;
    current->next=NULL;
    head->next->next=current;

    current=malloc(sizeof(struct node));
    current->data=30;
    current->next=NULL;
    head->next->next->next=current;

    current=malloc(sizeof(struct node));
    current->data=40;
    current->next=NULL;
    head->next->next->next=current;

    struct node *ptr=head;
    ptr=insertSort(head,23);
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;
}
struct node * insertSort(struct node *head,int data)
{
    struct node *temp1=malloc(sizeof(struct node));
    struct node *temp2=head;
    temp1->data=data;
    if (temp1->data < temp2->data || head==NULL )
    {
        temp1->next=temp2;
        temp2=temp1;
        temp2=head;
    }
    else
    {
        while (temp2->next!=NULL && temp1->data < temp2->next->data)
        {
            temp2=temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next=temp1;
        temp1=head;
    }
    return head;
}