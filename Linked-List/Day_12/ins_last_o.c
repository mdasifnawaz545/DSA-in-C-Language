#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node * add(struct node* head,int data);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node *ptr=head;
    ptr=add(ptr,10);
    ptr=add(ptr,20);
    ptr=add(ptr,30);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
    return 0;
}
struct node * add(struct node* ptr,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}