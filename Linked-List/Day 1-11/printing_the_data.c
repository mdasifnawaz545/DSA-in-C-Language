#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void display(struct node *head);
int main()
{
    struct node *head=(struct node*)calloc(1,sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node *current=(struct node *)calloc(1,sizeof(struct node));
    current->data=999;
    current->link=NULL;
    head->link=current;

    current=(struct node *)calloc(1,sizeof(struct node));
    current->data=888;
    current->link=NULL;
    head->link->link=current;


    current=(struct node *)calloc(1,sizeof(struct node));
    current->data=777;
    current->link=NULL;
    head->link->link->link=current;

    display(head);
    return 0;
}
void display(struct node *head)
{
    struct node *ptr=head;
    if (ptr==NULL)
    {
        printf("Linked List is Empty");
    }
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
}