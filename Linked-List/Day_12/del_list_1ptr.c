#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void del_last(struct node *);
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
    del_last(head);
    return 0;
}
void del_last(struct node *ptr1)
{
    int count=0;
    struct node *temp=ptr1;
    while (temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    temp=ptr1;
    while (count!=2)
    {
        temp=temp->link;
        count--;
    }
    temp->link=NULL;
    temp=ptr1;
        while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    
}
