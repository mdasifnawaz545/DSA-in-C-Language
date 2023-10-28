// Adding node at the end of the list.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void add(struct node* , int );
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;
     
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=687;
    current->link=NULL;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=877;
    current->link=NULL;
    head->link->link=current;

    add(head,796);

    return 0;
}
void add(struct node* head , int  n)
{
    struct node *ptr;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->link=NULL;
    ptr=head;

    while (ptr->link!=NULL)
    {
       ptr=ptr->link;
    }
    ptr->link=temp;
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;

    }
    
}