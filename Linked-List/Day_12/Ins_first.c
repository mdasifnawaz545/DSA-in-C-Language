#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* add_begin(struct node* head);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link->link=current;
    
    struct node *ptr=head;
    ptr=add_begin(head);
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
    return 0;
}

struct node* add_begin(struct node* head)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=786;
    temp->link=head;
    head=temp;

    return head;

}