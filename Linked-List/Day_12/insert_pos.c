#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void insert_pos(struct node*head,int data ,int pos);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=10;
    current->link=NULL;
    head->link=current;


    current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link->link=current;


    current=malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link->link->link=current;

    int data=30,pos=4;
    insert_pos(head,data,pos);
    return 0;
}
void insert_pos(struct node*head,int data ,int pos)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    struct node *ptr=head;
    pos--;
    while (pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
}