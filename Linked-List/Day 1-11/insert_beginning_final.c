#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *,int n);
void add_certain(struct node *head,int pos,int data);

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;
    struct node*ptr2=head;
    ptr2=add_at_end(head,787);
    ptr2=add_at_end(head,788);
    ptr2=add_at_end(head,789);
    ptr2=add_at_end(head,791);
    ptr2=add_at_end(head,792);

int data=790,pos;
printf("Enter the Positon : ");
scanf("%d",&pos);
add_certain(head,pos,data);
    struct node*ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
    return 0;
}
struct node* add_at_end(struct node *head,int n)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=n;
    temp->link=NULL;
    struct node*ptr;
    ptr=head;
    ptr->link=temp;
    return temp;
}
void add_certain(struct node *head,int pos,int data)
{
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr=head;
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